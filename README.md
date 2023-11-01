# Data-compressor
This tool can be used to reduce the memory usage of matrix like objects that only have few states for each field. 
In this case each of the NxN fields can have one of 4 predefined states. This compressor is reducing data occupacy by 4.
So if you have a matrix of 10x10, that is using 100 bayts this compressor will store all this data into a 25 bayt string. 
Then by using the decompress function you can recover the board.
