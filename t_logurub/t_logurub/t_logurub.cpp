// t_logurub.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../../logurub.hpp"
#include <boost/thread.hpp>

void sleep_ms(int ms)
{
	VLOG_F(2, "Sleeping for %d ms", ms);
	boost::this_thread::sleep_for(boost::chrono::milliseconds(ms));
}

void complex_calculation()
{
	LOG_SCOPE_F(INFO, "complex_calculation");
	LOG_F(INFO, "Starting time machine...");
	sleep_ms(200);
	LOG_F(WARNING, "The flux capacitor is not getting enough power!");
	sleep_ms(400);
	LOG_F(INFO, "Lighting strike!");
	VLOG_F(1, "Found 1.21 gigawatts...");
	sleep_ms(400);
	boost::thread([](){
		loguru::set_thread_name("the past");
		LOG_F(ERROR, "We ended up in 1985!");
	}).join();
}

int _tmain(int argc, char* argv[])
{
	loguru::init(argc, argv);
	loguru::add_file("everything.log", loguru::Append, loguru::Verbosity_MAX);

	LOG_F(INFO, "Hello from main.cpp!");
	complex_calculation();
	LOG_F(INFO, "main function about to end!");

	return 0;
}
