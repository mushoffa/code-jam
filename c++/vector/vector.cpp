#include <condition_variable>
#include <chrono>
#include <iostream>
#include <pthread.h>
// #include <semaphore>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

#define NUM_THREADS 5

condition_variable cv;
mutex cv_m;
int PORT_TO_FIND = 29320;
bool isDetected = false;

struct thread_data {
	int id;
	// char *message;
	pair<int, int> ports;
};

void *detect_frida_thread(void *args) {
	unique_lock<mutex> lck(cv_m);
	// cv.wait(lck, []{return  1;});
	// time_t start, end;
	auto start = chrono::steady_clock::now();
	
	struct thread_data *data;
	data = (struct thread_data *) args;

	int port_start = data->ports.first;
	int port_end = data->ports.second;

	// time(&start);
	// clock.tick();
	for(port_start; port_start <= port_end; port_start++) {
		printf("thread_id: %d -- port:%d\n", data->id, port_start);
		if(port_start == PORT_TO_FIND) {
			isDetected = true;
			cv.notify_all();
			printf("thread_id: %d -- PORT is detected\n", data->id);
			auto end = chrono::steady_clock::now();
			int elapsedTime = chrono::duration_cast<chrono::milliseconds>(end - start).count();
			printf("thread_id: %d, elapsed time %d ms\n", data->id, elapsedTime);
			pthread_exit(NULL);
		}

		if(isDetected) {
			printf("thread_id: %d is exiting", data->id);
			pthread_exit(NULL);
		}
	}

	auto end = chrono::steady_clock::now();
	int elapsedTime = chrono::duration_cast<chrono::milliseconds>(end - start).count();
	printf("thread_id: %d, elapsed time %d ms\n", data->id, elapsedTime);
	// cout << "Elapsed time in milliseconds: "
 //        << chrono::duration_cast<chrono::milliseconds>(end - start).count()
 //        << " ms" << endl;
	// clock.tock();

	// printf("Elapsed time %.lf\n", clock.elapsed_time());
	// time(&end);
	// double elapsedTime = difftime(end,start);
	// printf("Elapsed time: %.2lf seconds\n", elapsedTime);

	pthread_exit(NULL);
}

void test_case() {
	vector<pair<int, int>> ports {
		{25000, 26250},
		{26251, 27500},
		{27501, 28750},
		{28751, 30000}
	};	

	int total_threads = ports.size();
	int rc;

	pthread_t threads[total_threads];
	struct thread_data td[total_threads];

	// time_t start, end;
	// string test = "123456";
	// printf("%s\n", test);
	// printf("Size: %lu", ports.size());
	printf("Size: %zd\n", ports.size());
	// time(&start);
	for (int i = 0; i < ports.size(); i++) {
		// printf("From:%d ~ To:%d", ports[i].first, ports[i].second);
		td[i].id = i;
		td[i].ports = ports[i];
		rc = pthread_create(&threads[i], NULL, detect_frida_thread, (void *) &td[i]);
		pthread_join(threads[i], NULL);
		// threads[i].join();

		if(rc) {
			printf("Unable to create thread\n");
			exit(-1);
		}
		// puts("");
	}

	// time(&end);
	// double elapsedTime = difftime(end,start);
	// printf("Elapsed time: %.2lf seconds\n", elapsedTime);
	// puts("");

	pthread_exit(NULL);
}

int main() {
	// int T;
	// scanf("%d", &T);

	// tc means test case
	// for(int tc = 1; tc <= T; tc++) {
	// 	test_case();
	// }
	test_case();
}