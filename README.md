# binclude
binclude converts binary files to C/C++ arrays

Sometimes we need the binary of a file directly embedded in our C/C++ applications. This tiny program can do that for us.

The program can be built simply with..

    gcc binclude.c -o binclude
    
For usage, run without any arguments..

    ./binclude 

Which outputs..

    binclude converts binary files to C/C++ arrays
        usage:  binclude [filename] [array name] [optional column width] > target.c

Then run binclude with any binary file you need as data in your C/C++ program, optionaly with the column width. This defaults to 8.

    ./binclude monty.prg monty 4
    
This will output to stdout..

    const unsigned char monty[] = {
        0x00,0x80,0x00,0x70,
        0x00,0x70,0x00,0xc2,
        0xcd,0x38,0x30,0x4c,
        0x89,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0xa9,0x0f,0x8d,0x18,
        0xd4,0xee,0xfa,0x84,
        0x2c,0xee,0x84,0x30,
        0x1e,0x50,0x31,0xa9,
        0x00,0x8d,0xfa,0x84,
        0xa2,0x02,0x9d,0xc4,
        0x84,0x9d,0xc7,0x84,
        0x00,0x00,0x00,0x00,
        0x00,0x00
    };

To write this to a file...

    ./binclude monty.prg monty 4 >monty.c

Should you need different types defined etc it would be very simple for you to edit the source of binclude to meet your needs.

Since this is really boring and you read this far, here's a link to a music video I made..

[![Dirty Bokeh](https://storage.googleapis.com/kyoto.catchpole.net/dirty-bokeh1.jpg)](http://www.youtube.com/watch?v=DRQv5uO5xM0)

