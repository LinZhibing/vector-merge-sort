//
// Created by 林芷冰 on 2/18/22.
//

#ifndef CS590_RANDOM_GENERATOR_H
#define CS590_RANDOM_GENERATOR_H
#include <string>

#define HAVE_RANDOM
#define HAVE_SRANDOM

#if defined(HAVE_RANDOM) && defined(HAVE_SRANDOM)
#define RANDOM random
#define SRANDOM srandom
#else
#if defined(HAVE_RAND) && defined(HAVE_SRAND)
#define RANDOM rand
#define SRANDOM srand
#else
#error "random/srandom functions missing!"
#endif
#endif

using namespace std;

class random_generator {
    private:
        static bool 		initialized;

    public:
    /*
     * constructor/destructor
     */
        random_generator()
        { if (!initialized) seed(); }
        ~random_generator()
        { }

    private:
    /*
     * inhibit:
     */
        random_generator(const random_generator&);
        random_generator& operator = (const random_generator&);

    public:
        static void seed(unsigned int = 0xa4295f21);

        char* random_string(int, int&);
        char* random_string_m(int, int);
};
random_generator& operator >> (random_generator&, int&);
random_generator& operator >> (random_generator&, long&);
random_generator& operator >> (random_generator&, double&);


#endif //CS590_RANDOM_GENERATOR_H
