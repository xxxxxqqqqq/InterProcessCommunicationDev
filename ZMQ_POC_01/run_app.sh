xterm -hold -e bin/PortGenerator -comps A B C D E -port 5555 -simtime 1000 & 
xterm -hold -e bin/CompA -port 5555 -simtime 1000 -exectime 30 &
xterm -hold -e bin/CompB -port 5555 -simtime 1000 -exectime 20 &
xterm -hold -e bin/CompC -port 5555 -simtime 1000 -exectime 10 &
xterm -hold -e bin/CompD -port 5555 -simtime 1000 -exectime 20 &
xterm -hold -e bin/CompE -port 5555 -simtime 1000 -exectime 40 &
