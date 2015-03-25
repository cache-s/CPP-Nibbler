//
// Exception.hpp for nibbler in /home/chazot_a/rendu/cpp_nibbler
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Wed Mar 25 11:42:12 2015 Jordan Chazottes
// Last update Wed Mar 25 11:51:31 2015 Jordan Chazottes
//

#ifndef			EXCEPTION_HPP_
# define		EXCEPTION_HPP_

# include		<exception>
# include		<string>

class Exception : public std::exception
{
public:
  explicit Exception(const char* _error) : error(_error)
  {
  }

  virtual const char* what() const throw()
  {
    return error;
  }
protected:
  const char*           error;
};

class RuntimeError : public virtual std::runtime_error, public Exception
{
public:
  explicit RuntimeError(const char *_error) : error(_error)
  {
  }
};

#endif			// EXCEPTION_HPP_
