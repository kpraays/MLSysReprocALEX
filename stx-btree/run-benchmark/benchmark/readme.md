### How to Compile the benchmark (main.cpp)?
$ g++ main.cpp -o main -std=c++11 -O2 -DNDEBUG -I ../../include
$ ./main

- Since all the header files are in the same directory as your source file, the compiler will be able to find them automatically.
- For utils.h, flags.h and zipf.h.
- -I ../../include --> refers to implementation of B+ tree.

### How to run benchmark on sample binary data?
./main \
--keys_file=../resources/sample_keys.bin \
--keys_file_type=binary \
--init_num_keys=500 \
--total_num_keys=1000 \
--batch_size=1000 \
--insert_frac=0.5 \
--time_limit=20 \
--print_batch_stats=true

### longitudes
#define KEY_TYPE double
#define PAYLOAD_TYPE double

g++ main.cpp -o longitudes -std=c++11 -O2 -DNDEBUG -I ../../include

### longlat
#define KEY_TYPE double
#define PAYLOAD_TYPE double

g++ main.cpp -o longlat -std=c++11 -O2 -DNDEBUG -I ../../include


### lognormal
#define KEY_TYPE int64_t
#define PAYLOAD_TYPE double

g++ main.cpp -o lognormal -std=c++11 -O2 -DNDEBUG -I ../../include

### ycsb
#define KEY_TYPE uint64_t
#define PAYLOAD_TYPE double

g++ main.cpp -o ycsb -std=c++11 -O2 -DNDEBUG -I ../../include

**read only: 0% inserts**
./ycsb \
--keys_file=../data/ycsb-200M.bin \
--keys_file_type=binary \
--init_num_keys=500 \
--total_num_keys=20000 \
--batch_size=1000 \
--insert_frac=0 \
--time_limit=0.5 \
--print_batch_stats=true \
> outputs/ycsb/ycsb_read_only.txt

**read heavy: 5% inserts**
./ycsb \
--keys_file=../data/ycsb-200M.bin \
--keys_file_type=binary \
--init_num_keys=500 \
--total_num_keys=1000 \
--batch_size=1000 \
--insert_frac=0.05 \
--time_limit=20 \
--print_batch_stats=true \
> outputs/ycsb/ycsb_read_heavy.txt

**write heavy: 50% inserts**
./ycsb \
--keys_file=../data/ycsb-200M.bin \
--keys_file_type=binary \
--init_num_keys=500 \
--total_num_keys=1000 \
--batch_size=1000 \
--insert_frac=0.5 \
--time_limit=20 \
--print_batch_stats=true \
> outputs/ycsb/ycsb_write_heavy.txt

