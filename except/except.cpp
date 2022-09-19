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
* @file except.cpp
* @author Thibault Falque
* @author Romain Wallon
* @date 18/09/22
* @brief
* @copyright Copyright (c) 2022 Exakis Nelite, Université d'Artois & CNRS
* @license This project is released under the GNU LGPL3 License.
*/


#include "except.hpp"

#include <utility>
#include <cstring>

using namespace std;
using namespace Except;

Exception::Exception(string message) :
        message(move(message)) {
    // Nothing to do: all fields are already initialized.
}

const char *Exception::what() const noexcept {
    return message.c_str();
}

IllegalArgumentException::IllegalArgumentException(string message) :
        Exception(move(message)) {
    // Nothing to do: all fields are already initialized.
}

IllegalStateException::IllegalStateException(string message) :
        Exception(move(message)) {
    // Nothing to do: all fields are already initialized.
}

ParseException::ParseException(string message) :
        Exception(move(message)) {
    // Nothing to do: all fields are already initialized.
}

UnsupportedOperationException::UnsupportedOperationException(string message) :
        Exception(move(message)) {
    // Nothing to do: all fields are already initialized.
}
OSException::OSException(std::string message) : Exception(std::to_string(errno)+": "+std::move(message)+" "+std::strerror(errno)) {

}


