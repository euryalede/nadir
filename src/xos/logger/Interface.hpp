///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2018 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: Interface.hpp
///
/// Author: $author$
///   Date: 4/16/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_LOGGER_INTERFACE_HPP
#define _XOS_LOGGER_INTERFACE_HPP

#include "xos/base/Base.hpp"

namespace xos {
namespace logger {


} /// namespace logger
} /// namespace xos

#if !defined(LOG_FATAL)
#if defined(XOS_LOG_FATAL)
#define LOG_FATAL(__message__) XOS_LOG_FATAL(__message__)
#else /// defined(XOS_LOG_FATAL)
#define LOG_FATAL(__message__)
#endif /// defined(XOS_LOG_FATAL)
#endif /// !defined(LOG_FATAL)

#if !defined(LOG_ERROR)
#if defined(XOS_LOG_ERROR)
#define LOG_ERROR(__message__) XOS_LOG_ERROR(__message__)
#else /// defined(XOS_LOG_ERROR)
#define LOG_ERROR(__message__)
#endif /// defined(XOS_LOG_ERROR)
#endif /// !defined(LOG_ERROR)

#if !defined(LOG_WARN)
#if defined(XOS_LOG_WARN)
#define LOG_WARN(__message__) XOS_LOG_WARN(__message__)
#else /// defined(XOS_LOG_WARN)
#define LOG_WARN(__message__)
#endif /// defined(XOS_LOG_WARN)
#endif /// !defined(LOG_WARN)

#if !defined(LOG_INFO)
#if defined(XOS_LOG_INFO)
#define LOG_INFO(__message__) XOS_LOG_INFO(__message__)
#else /// defined(XOS_LOG_INFO)
#define LOG_INFO(__message__)
#endif /// defined(XOS_LOG_INFO)
#endif /// !defined(LOG_INFO)

#if !defined(LOG_DEBUG)
#if defined(XOS_LOG_DEBUG)
#define LOG_DEBUG(__message__) XOS_LOG_DEBUG(__message__)
#else /// defined(XOS_LOG_DEBUG)
#define LOG_DEBUG(__message__)
#endif /// defined(XOS_LOG_DEBUG)
#endif /// !defined(LOG_DEBUG)

#if !defined(LOG_TRACE)
#if defined(XOS_LOG_TRACE)
#define LOG_TRACE(__message__) XOS_LOG_TRACE(__message__)
#else /// defined(XOS_LOG_TRACE)
#define LOG_TRACE(__message__)
#endif /// defined(XOS_LOG_TRACE)
#endif /// !defined(LOG_TRACE)

#endif /// _XOS_LOGGER_INTERFACE_HPP 
