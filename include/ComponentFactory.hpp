//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef COMPONENTFACTORY_HPP_
# define COMPONENTFACTORY_HPP_

#include "IComponent.hpp"
#include <memory>
#include <map>
#include <string>

namespace nts
{
	class ComponentFactory
	{
	public:
		ComponentFactory();
		typedef std::unique_ptr<IComponent> (*CreateFunc)
			(const std::string &value);
		typedef std::map<std::string, CreateFunc> CreationFuncMap;
		std::unique_ptr<IComponent> createComponent(const std::string &type,
		  const std::string &name, std::string const &value = "");
	private:
		static CreationFuncMap _creationFuncs;
	};
}

#endif /* !COMPONENTFACTORY_HPP_ */
