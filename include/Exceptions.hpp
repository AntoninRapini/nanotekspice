//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef EXCEPTIONS_HPP_
# define EXCEPTIONS_HPP_

namespace nts
{
	class NtsError : public std::exception
	{
	public:
		NtsError(std::string const &message);
	};

	class PinError : public NtsError
	{
	public:
		PinError(std::string const &message);
	};

	class LinkError : public PinError
	{
	public:
		LinkError(std::string const &message);
	};
}

#endif /* !EXCEPTIONS_HPP_ */
