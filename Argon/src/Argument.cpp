#include "Argument.h"
#include "Type.h"

#include <ostream>

namespace Argon
{
    Argument::Argument(std::string argName) : m_argName(std::move(argName)),
                                              m_type(Type::None),
                                              m_isRequired(false),
                                              m_isSet(false),
                                              m_helpText()
    {
    }

    const Type
    Argument::getType() const
    {
        return this->m_type;
    }
    const std::string &
    Argument::getHelpText() const
    {
        return m_helpText;
    }

    bool
    Argument::isRequired() const
    {
        return m_isRequired;
    }

    bool
    Argument::isSet() const
    {
        return m_isSet;
    }

    Argument &
    Argument::setArg(const char *newValue)
    {
        this->m_arg = std::make_shared<std::string>(std::string(newValue));
        this->m_isSet = true;
        return *this;
    }

    Argument &
    Argument::setArg(const int newValue)
    {
        this->m_arg = std::make_shared<int>(newValue);
        this->m_isSet = true;
        return *this;
    }

    Argument &
    Argument::setArgName(const std::string &argName)
    {
        m_argName = argName;
        return *this;
    }

    Argument &
    Argument::setType(Type type)
    {
        m_type = type;
        return *this;
    }

    Argument &
    Argument::setIsRequired(bool isRequired)
    {
        m_isRequired = isRequired;
        return *this;
    }

    Argument &
    Argument::setHelpText(const std::string &helpText)
    {
        m_helpText = helpText;
        return *this;
    }

    std::ostream &
    operator<<(std::ostream &os, const Argument &arg)
    {
        os << "m_arg: ";

        switch (arg.m_type)
        {
        case Type::Integer:
            os << (*std::get<std::shared_ptr<int>>(arg.m_arg)) << std::endl;
            os << "m_type: Integer" << std::endl;
            break;
        case Type::String:
            os << (*std::get<std::shared_ptr<std::string>>(arg.m_arg)) << std::endl;
            os << "m_type: String" << std::endl;
            break;
        default:
            break;
        }
        os << "m_helpText: "
           << arg.m_helpText << std::endl
           << "m_isRequired: "
           << arg.m_isRequired << std::endl;
        return os;
    }
}