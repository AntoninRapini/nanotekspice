//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef EXCEPTIONS_HPP_
# define EXCEPTIONS_HPP_

#include <string>
#include <exception>

namespace nts
{
	class NtsError : public std::exception
	{
	public:
		NtsError(std::string const &message);
		const char *what() const noexcept;
	private:
		std::string _message;
	};

	class ComputeError : public NtsError
	{
	public:
		ComputeError(std::string const &message);
	};

	class LinkError : public NtsError
	{
	public:
		LinkError(std::string const &message);
	};

	class SetError : public NtsError
	{
	public:
		SetError(std::string const &message);
	};
}

#endif /* !EXCEPTIONS_HPP_ */
