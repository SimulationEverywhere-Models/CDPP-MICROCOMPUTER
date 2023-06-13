[top]
components : keyboard@Keyboard 
components : Motherboard 
components : harddisk@Harddisk 
components : monitor@Monitor
out : out hd_out
in : in 
Link : in in@keyboard
Link : out@keyboard key_in@motherboard
Link : hd_out@motherboard in@harddisk
Link : done@harddisk hd_done@motherboard
Link : monitor_out@motherboard in@monitor
Link : out@monitor out
Link : out@harddisk hd_out

[Motherboard]
components : cpu@cpu 
components : memory@memory
out : hd_out
out : monitor_out
in : hd_done
in : key_in
Link : key_in in@memory
Link : out@memory memory_in@cpu
Link : job_done@cpu done@memory
Link : hd_out@cpu hd_out
Link : hd_done hd_done@cpu
Link : monitor_out@cpu monitor_out


[keyboard]
preparation : 00:00:00:003 

[monitor]
preparation : 00:00:00:003

[harddisk]
preparation : 00:00:00:020

[cpu]
preparation : 00:00:00:001

[memory]
preparation : 00:00:00:002

