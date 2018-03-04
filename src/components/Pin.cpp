//
// EPITECH PROJECT, 2018
// NanoTekSpice
// File description:
// 
//

#include "Pin.hpp"
#include "AComponent.hpp"
#include <iostream>

namespace nts {
    Pin::Pin(IComponent *owner, Type type, Tristate value) :
            _owner(owner), _type(type), _value(value),
            _isbeingcomputed(false), _needComputation(true) {
        _index = ((AComponent *) _owner)->getPins().size() + 1;
    }

    void Pin::setNeedComputation(bool value) {
        _needComputation = value;
    }

    Tristate Pin::compute() {
        if (_value == Tristate::UNDEFINED || _needComputation) {
            _needComputation = false;
            if (_isbeingcomputed) {
                _isbeingcomputed = false;
                _value = Tristate::UNDEFINED;
            } else {
                _isbeingcomputed = true;
                _value = _owner->compute(_index);
            }
        }
        _isbeingcomputed = false;
        return _value;
    }

    Tristate Pin::getValue() const {
        return _value;
    }


    Pin::Type Pin::getType() const {
        return _type;
    }

    void Pin::setValue(nts::Tristate value) {
        _value = value;
    }

    const IComponent *Pin::getOwner() const {
        return _owner;
    }
}
