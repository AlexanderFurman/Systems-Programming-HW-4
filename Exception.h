//
// Created by alex on 1/15/23.
//

#ifndef HW3_CLION_EXCEPTION_H
#define HW3_CLION_EXCEPTION_H

#include <exception>
#include <utilities.h>

class InvalidNameException : public std::exception {};
class InvalidMerchantInput : public std::exception {};

#endif //HW3_CLION_EXCEPTION_H
