//
// Created by 林芷冰 on 2/18/22.
//

#ifndef CS590_TIMER_H
#define CS590_TIMER_H
#include <iostream>
#include <list>
#include <string>

#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/times.h>

using namespace std;
class timer {
private:
    static const double 		t_granularity;
    static const double 		t_granularity_min;
    static const double 		t_granularity_hour;
    static const double 		t_granularity_day;

    static double 			t_granularity_factor;
    static long 			t_clock_ticks;

    struct timeval			t_tv;
    struct timezone			t_tz;

    long 				t_user;
    long				t_sys;

    long 				t_user_total;
    long				t_sys_total;
    long				t_real_total;

    bool 				t_print_mode;

/*
 * global timers
 */
    static list< pair<timer*,string> >	t_gt;

public:
    timer();
    timer(const timer&);
    ~timer();

    static long clock_ticks();

    void set_print_mode_time()
    { t_print_mode = true; }
    void set_print_mode_hms()
    { t_print_mode = false; }

    void start();
    void stop();
    void cont();

    void reset();

    long user() const
    { return t_user_total; }
    long sys() const
    { return t_sys_total; }
    long real() const
    { return t_real_total; }

/*
 * operators
 */
    timer& operator = (const timer&);

    timer operator + (const timer&);
    timer operator - (const timer&);
    timer operator / (double);

/*
 * output
 */
    void print(ostream& = cout) const;

    friend ostream& operator << (ostream&, const timer&);


/*
 * global timers
 */
    static void gt_init();
    static timer* gt_add(string);
    static list< pair<timer*,string> >* gt_access();
};


#endif //CS590_TIMER_H
