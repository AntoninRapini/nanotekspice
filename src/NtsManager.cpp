//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include "LogicGates.hpp"
#include "NtsManager.hpp"
#include "Exceptions.hpp"
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <iostream>

namespace nts {
    void NtsManager::ChangePinValue
            (const std::string &name, Tristate value, std::size_t pin, bool startup) {
        try {
            AComponent &to_change = dynamic_cast<AComponent &>((*_components.at(name)));
            if (to_change.getType().compare("Input") != 0) {
                if (startup && to_change.getType().compare("Clock") != 0)
                    throw (SetError("Requested component is not modifiable"));
            }
            to_change.setPinValue(pin, value);
        }
        catch (const std::out_of_range &e) {
            throw (SetError("Requested component does not exist"));
        }
        catch (const SetError &e) {
            throw (SetError(e.what()));
        }
    }

    void NtsManager::DisplayPinValue
            (const std::string &name, AComponent &component, std::size_t pin) {
        Tristate value = component.getPins()[pin - 1]->getValue();
        std::cout << name << "=" << value << std::endl;
    }

    void NtsManager::Display() {
        for (auto it = _components.begin(); it != _components.end(); it++) {
            if (dynamic_cast<AComponent &>(*(it->second)).getType().compare("Output") == 0)
                DisplayPinValue(it->first, dynamic_cast<AComponent &>(*(it->second)));
        }
    }

    void NtsManager::Simulate() {
        for (auto it = _components.begin(); it != _components.end(); it++) {
            if (dynamic_cast<AComponent &>(*(it->second)).getType().compare("Output") == 0) {
                dynamic_cast<AComponent &>(*(it->second)).getPins()[0]->setNeedComputation(true);
                it->second->compute();
            }
        }
        for (auto it = _components.begin(); it != _components.end(); it++) {
            if (dynamic_cast<AComponent &>(*(it->second)).getType().compare("Clock") == 0) {
                dynamic_cast<AComponent &>(*(it->second)).setPinValue(1,
                                                                      !dynamic_cast<AComponent &>(*(it->second)).getPins()[0]->getValue());
            }
        }
    }

    void NtsManager::Dump() {
        for (auto it = _components.begin(); it != _components.end(); it++) {
            it->second->dump();
        }
    }

    std::map<std::string, std::unique_ptr<IComponent>> &NtsManager::getComponents() {
        return _components;
    }
}
