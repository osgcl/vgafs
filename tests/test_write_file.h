
#include "libs/cltest/cltest/assert.h"
#include "libs/cltest/cltest/macros.h"

#include "tests/utils_on_path.h"

#include "vgafs/file.h"
#include <cstring>

CLTEST(test_write_gitignore) {
    const char* line_expected = "# this line is used by the testing tools to validate read";

    osgcl::vgafs::FStream* stream = osgcl::vgafs::open(".test", "w");

    assert_true(stream->is_open());

    std::size_t size = strlen(line_expected);

    char buffer[size + 1];
    buffer[size] = 0;
    for (int i = 0; i < size; i ++) buffer[i] = line_expected[i];

    std::size_t res = stream->write( buffer, size );
    assert_equals(res, size);

    delete stream;

    assert_file_read( ".test", line_expected );
}
