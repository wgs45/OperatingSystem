Operating System Assignment

Process vs Thread — Login System Simulation (Chinese Version)

I. Assignment Objectives

• Implement Client-Server login using TCP Sockets.

• Implement two server models: fork (one Process per connection) and pthread (one Thread per connection).

• Measure performance: latency, success rate, CPU/memory usage, and context switching.

• Learn how to detect and diagnose bottlenecks and problems in concurrent systems.

• Write an evidence-based analysis report.

II. System Specifications

• Reads users.txt (format: username password) upon server startup.

• Client sends: username password

• Server returns: OK or FAIL

• Closes the connection after receiving the response.

• Required:

1. login_server_fork.c — forks a child process for each connection

2. login_server_thread.c — creates a pthread for each connection for processing

III. Required Submission Programs

1. login_server_fork.c (Process-per-connection)

2. login_server_thread.c (Thread-per-connection)

3. login_client.c (Single login test)

4. login_stress.c (Stress test program: total_requests + concurrency)

5. run_tests.sh (Automatic test script)

IV. Measurement Items (Evidence Required) During stress testing, please record the following information:

• /usr/bin/time -v output (User/System time, Max RSS, Context Switch)

• htop / top screenshot (Number of Processes/Threads)

• ps -L -p <pid> (Server Thread/Process list)

• pmap -x <pid> (Memory configuration)

• Latency Records (Average, Maximum, P95)

• Success Rate, Timeout Rate

V. Experiment Requirements

• Test the fork and thread versions with concurrency = 10, 50, 100, and 200 respectively.

• Record the performance of both under the same load.

• Compare the difference in the number of processes and threads.

• Compare the difference in memory usage (Max RSS).

• Identify possible causes of bottlenecks, such as: CPU overload, excessive Context Switches, memory pressure, etc.

VI. Mandatory Report Questions

1. System Resource Comparison

• How many processes/threads does the fork and thread versions generate under high concurrency?

• What is the difference in Max RSS? What are the reasons?

2. Performance and Latency Comparison

• Which mode has lower latency?

• Are there any timeouts? Under what concurrency levels do they occur?

• What is the difference in the number of Context Switches? How do you explain it?

3. Troubleshooting Methods

• If a timeout occurs, what are your diagnostic steps? Please write down your "Problem Detection Checklist".

4. Conclusion

• When should you use a process? When should you use a thread?

• If you were a system architect, would you switch to a thread pool or event-driven approach? Why?

VII. Submissions

• Complete source code

• Test script (run_tests.sh)

• Measurement output (log and screenshots)

• Final report (PDF or Word)
