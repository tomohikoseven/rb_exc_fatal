#include <stdio.h>
#include "ruby.h"
#include "ruby/ruby.h"

// クラス
VALUE cFatal;

VALUE
raise_fatal( VALUE self )
{
    //rb_exc_raise( cFatal );
    rb_exc_fatal( cFatal );
    return Qnil;
}
void
Init_libfatal()
{
    cFatal = rb_define_class( "Fatal", rb_eFatal );

    rb_define_method( cFatal, "do_fatal", raise_fatal, 0 );
 
}
