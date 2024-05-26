
#include "libs/cltest/cltest/assert.h"
#include "libs/cltest/cltest/macros.h"

#include "vgafs/file.h"

CLTEST(test_open_read) {
    osgcl::vgafs::FStream* stream = osgcl::vgafs::open(".gitignore", "r");

    assert_true(stream->is_open());
    
    delete stream;
    stream = osgcl::vgafs::open(".empty", "r");

    assert_false(stream->is_open());
    
    delete stream;
}

CLTEST(test_open_write) {
    osgcl::vgafs::FStream* stream = osgcl::vgafs::open(".test", "w");

    assert_true(stream->is_open());

    delete stream;
}
