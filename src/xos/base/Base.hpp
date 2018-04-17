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
///   File: Base.hpp
///
/// Author: $author$
///   Date: 4/14/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_BASE_HPP
#define _XOS_BASE_BASE_HPP

#include "xos/platform/Platform.hpp"

namespace xos {

///////////////////////////////////////////////////////////////////////
///  Class: ImplementBase
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS ImplementBase {
public:
    virtual ~ImplementBase() {
    }
};

///////////////////////////////////////////////////////////////////////
///  Class: Base
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Base: virtual public ImplementBase {
public:
    typedef ImplementBase Implements;
    
    Base(const Base &copy) {
    }
    Base() {
    }
    virtual ~Base() {
    }
};

///
/// To Pointer / Unsigned / Signed / WChar / TChar / Char / Bool
/// 
inline const pointer_t& ToPointer(const pointer_t& v) { return v; }
inline const unsigned& ToUnsigned(const unsigned& v) { return v; }
inline const signed& ToSigned(const signed& v) { return v; }
inline const wchar_t& ToWChar(const wchar_t& v) { return v; }
inline const tchar_t& ToTChar(const tchar_t& v) { return v; }
inline const char& ToChar(const char& v) { return v; }
inline const word_t& ToWord(const word_t& v) { return v; }
inline const byte_t& ToByte(const byte_t& v) { return v; }
inline const bool& ToBool(const bool& v) { return v; }

///
/// MSeconds Seconds / MSeconds / USeconds / NSeconds
/// 
inline seconds_t MSecondsSeconds
(mseconds_t mseconds) { return mseconds / 1000; }

inline mseconds_t MSecondsMSeconds
(mseconds_t mseconds) { return mseconds % 1000; }

inline useconds_t MSecondsUSeconds
(mseconds_t mseconds) { return MSecondsMSeconds(mseconds) * 1000; }

inline nseconds_t MSecondsNSeconds
(mseconds_t mseconds) { return MSecondsUSeconds(mseconds) * 1000; }

} /// namespace xos

#endif /// _XOS_BASE_BASE_HPP 
