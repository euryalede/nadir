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
///   File: Exception.hpp
///
/// Author: $author$
///   Date: 4/16/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_EXCEPTION_HPP
#define _XOS_BASE_EXCEPTION_HPP

#include "xos/base/String.hpp"

namespace xos {

typedef int  ExceptionStatus;
enum {
    ExceptionSuccess,
    ExceptionFailed
};
template <class TString>
inline TString ExceptionStatusToString(ExceptionStatus status) {
    switch (status) {
    case ExceptionSuccess: return TString("ExceptionSuccess");
    case ExceptionFailed: return TString("ExceptionFailed");
    }
    return TString("Unknown");
}
typedef ImplementBase ExceptionTImplements;
typedef Base ExceptionTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: ExceptionT
///////////////////////////////////////////////////////////////////////
template 
<typename TStatus = ExceptionStatus, class TString = String,
 class TImplements = ExceptionTImplements, class TExtends = ExceptionTExtends>
class _EXPORT_CLASS ExceptionT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TStatus status_t;
    typedef TString string_t;
    
    ExceptionT(const status_t& status): _status(status) {
    }
    ExceptionT(const ExceptionT &copy): _status(copy.Status()) {
    }
    ExceptionT(): _status(ExceptionFailed) {
    }
    virtual ~ExceptionT() {
    }

    virtual string_t StatusToString() const {
        return ExceptionStatusToString<string_t>(_status);
    }
    virtual status_t Status() const {
        return _status;
    }

protected:
    status_t _status;
};
typedef ExceptionT<> Exception;

} /// namespace xos

#endif /// _XOS_BASE_EXCEPTION_HPP 
