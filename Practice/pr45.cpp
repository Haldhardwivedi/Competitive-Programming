#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

// Defining process details
struct process {
	char name;
	int at, bt, ct, wt, tt;
	int completed;
	float ntt;
} p[10];

int n;

// Sorting Processes by Arrival Time
void sortByArrival()
{
	struct process temp;
	int i, j;

	// Selection Sort applied
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {

			// Check for lesser arrival time
			if (p[i].at > p[j].at) {

				// Swap earlier process to front
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
}



int main()
{
      int i, limit, total = 0, x, counter = 0, time_quantum;
      int wait_time = 0, turnaround_time = 0, arrival_time[10], burst_time[10], temp[10];
      float average_wait_time, average_turnaround_time;
      printf("Enter Total Number of Processes:  ");
      scanf("%d", &limit);
      x = limit;
      n=limit;
      for(i = 0; i < limit; i++)
      {
            printf("Enter Details of Process[%d]\n", i + 1);
 
            printf("Arrival Time: ");
 
            scanf("%d", &arrival_time[i]);
 
            printf("Burst Time: ");
 
            scanf("%d", &burst_time[i]);
 
            temp[i] = burst_time[i];
      }
 
      printf("Enter Time Quantum:  ");
      scanf("%d", &time_quantum);
      for(total = 0, i = 0; x != 0;)
      {
            if(temp[i] <= time_quantum && temp[i] > 0)
            {
                  total = total + temp[i];
                  temp[i] = 0;
                  counter = 1;
            }
            else if(temp[i] > 0)
            {
                  temp[i] = temp[i] - time_quantum;
                  total = total + time_quantum;
            }
            if(temp[i] == 0 && counter == 1)
            {
                  x--;
                  //printf("nProcess[%d]tt%dtt %dttt %d", i + 1, burst_time[i], total - arrival_time[i], total - arrival_time[i] - burst_time[i]);
                  wait_time = wait_time + total - arrival_time[i] - burst_time[i];
                  turnaround_time = turnaround_time + total - arrival_time[i];
                  counter = 0;
            }
            if(i == limit - 1)
            {
                  i = 0;
            }
            else if(arrival_time[i + 1] <= total)
            {
                  i++;
            }
            else
            {
                  i = 0;
            }
      }
      cout<<"For Round Robin"<<endl;
      average_wait_time = wait_time * 1.0 / limit;
      average_turnaround_time = turnaround_time * 1.0 / limit;
      printf("Average Waiting Time:   %f\n", average_wait_time);
      printf("Avg Turnaround Time:   %f \n", average_turnaround_time);

    // Initializing the structure variables HRRN
    char c;
    int  t, sum_bt = 0;
    float avgwt = 0, avgtt = 0;
	for (i = 0, c = 'A'; i < n; i++, c++) 
    {
		p[i].name = c;
		p[i].at = arrival_time[i];
		p[i].bt = burst_time[i];

		// Variable for Completion status
		// Pending = 0
		// Completed = 1
		p[i].completed = 0;

		// Variable for sum of all Burst Times
		sum_bt += p[i].bt;
	}

	// Sorting the structure by arrival times
	sortByArrival();
	for (t = p[0].at; t < sum_bt;) 
    {

		// Set lower limit to response ratio
		float hrr = -9999;

		// Response Ratio Variable
		float temp;

		// Variable to store next process selected
		int loc;
		for (i = 0; i < n; i++) {

			// Checking if process has arrived and is Incomplete
			if (p[i].at <= t && p[i].completed != 1) {

				// Calculating Response Ratio
				temp = (p[i].bt + (t - p[i].at)) / p[i].bt;

				// Checking for Highest Response Ratio
				if (hrr < temp) {

					// Storing Response Ratio
					hrr = temp;

					// Storing Location
					loc = i;
				}
			}
		}

		// Updating time value
		t += p[loc].bt;

		// Calculation of waiting time
		p[loc].wt = t - p[loc].at - p[loc].bt;

		// Calculation of Turn Around Time
		p[loc].tt = t - p[loc].at;

		// Sum Turn Around Time for average
		avgtt += p[loc].tt;

		// Calculation of Normalized Turn Around Time
		p[loc].ntt = ((float)p[loc].tt / p[loc].bt);

		// Updating Completion Status
		p[loc].completed = 1;

		// Sum Waiting Time for average
		avgwt += p[loc].wt;
	}
    cout<<"For HRRN"<<endl;
	cout << "Average waiting time: " << avgwt<< endl;
	cout <<"Average Turn Around time:  "<< avgtt <<endl;
      return 0;
}