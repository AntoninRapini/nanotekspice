//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef COMPONENTFACTORY_HPP_
# define COMPONENTFACTORY_HPP_

#include "IComponent.hpp"
#include <map>
#include <memory>
#include <string>

namespace nts
{
	class ComponentFactory
	{
	public:
		ComponentFactory();
		typedef std::unique_ptr<IComponent> (*CreateFunc)
			(const std::string &value);
		typedef std::map<const std::string, CreateFunc> CreationFuncMap;
		std::unique_ptr<IComponent> createComponent(const std::string &type,
		  const std::string &value);
	private:
		static CreationFuncMap _creationFuncs;
	};
}

#endif /* !COMPONENTFACTORY_HPP_ */
