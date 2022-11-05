/******************************************************************************
 * Except - A library for exception in C++                               *
 * Copyright (c) 2022 - Univ Artois & CNRS & Exakis Nelite.                   *
 * All rights reserved.                                                       *
 *                                                                            *
 * This library is free software; you can redistribute it andor               *
 * modify it under the terms of the GNU Lesser General Public                 *
 * License as published by the Free Software Foundation; either               *
 * version 3 of the License, or (at your option) any later version.           *
 *                                                                            *
 * This library is distributed in the hope that it will be useful,            *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                       *
 * See the GNU Lesser General Public License for more details.                *
 *                                                                            *
 * You should have received a copy of the GNU Lesser General Public           *
 * License along with this library.                                           *
 * If not, see http:www.gnu.orglicenses.                              *
 ******************************************************************************/

/**
* @file except.hpp
* @author Thibault Falque
* @author Romain Wallon
* @date 18/09/22
* @brief
* @copyright Copyright (c) 2022 Exakis Nelite, Université d'Artois & CNRS
* @license This project is released under the GNU LGPL3 License.
*/


#ifndef Otis_EXCEPT_H
#define Otis_EXCEPT_H

#include <exception>
#include <string>

namespace Except {

    /**
     * @class Exception
     * @brief The Exception is the parent class of all exceptions that can be
     * thrown by Otis.
     *
     * @version 0.1.0
     */
    class Exception : public std::exception {

    private:

        /**
         * The message describing the problem that occurred.
         */
        std::string message;

    protected:

        /**
         * Creates a new Exception.
         *
         * @param message The message describing the problem that occurred.
         */
        explicit Exception(std::string message);

    public:

        /**
         * Gives the message describing the problem that occurred.
         *
         * @return The message of this exception.
         */
        [[nodiscard]] const char *what() const noexcept override;

    };

    /**
     * @class IllegalArgumentException
     * @brief The IllegalArgumentException is an exception that is thrown when an
     * argument given to a method or function does not match the expectations
     * for this method or function.
     *
     * @version 0.1.0
     */
    class IllegalArgumentException : public Except::Exception {

    public:

        /**
         * Creates a new IllegalArgumentException.
         *
         * @param message The message describing why the argument is illegal.
         */
        explicit IllegalArgumentException(std::string message);

    };

    /**
     * @class IllegalStateException
     * @brief The IllegalStateException is an exception that is thrown when an object
     * is not in an appropriate state to allow to invoke a method.
     *
     * @version 0.1.0
     */
    class IllegalStateException : public Except::Exception {

    public:

        /**
         *
         * @brief Creates a new IllegalStateException.
         *
         * @param message The message describing why the current state does not
         *        allow to invoke the method.
         */
        explicit IllegalStateException(std::string message);

    };

    /**
     * @class ParseException
     * @brief The ParseException is an exception that is thrown when a parser cannot
     * parse properly an input stream.
     *
     * @version 0.1.0
     */
    class ParseException : public Except::Exception {

    public:

        /**
         * Creates a new ParseException.
         *
         * @param message The message describing why parsing failed.
         */
        explicit ParseException(std::string message);

    };

    /**
     * @class UnsupportedOperationException
     * @brief The UnsupportedOperationException is an exception that is thrown when an
     * unsupported method is invoked.
     *
     * @version 0.1.0
     */
    class UnsupportedOperationException : public Except::Exception {

    public:

        /**
         * Creates a new UnsupportedOperationException.
         *
         * @param message The message describing why the method is not supported.
         */
        explicit UnsupportedOperationException(std::string message);

    };
    /**
     * @class OSException
     * @brief The OSException is an exception that is thrown when a
     * system call is invoked.
     *
     * @version 0.1.0
     */
    class OSException: public Except::Exception{
    public:
        /**
        * Creates a new OSException.
        *
        * @param message The message describing why the method is not supported.
        */
        explicit OSException(std::string message);
    };

}

#endif
