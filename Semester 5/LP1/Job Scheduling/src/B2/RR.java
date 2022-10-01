package B2;

import java.util.*;

public class RR
{
	private Scanner s;
	public void execute()
	{
		s = new Scanner(System.in);
		System.out.print("Please enter the number of processes.\nNumber of Processes: ");
		int numProcess = s.nextInt();
		Process process[] = new Process[numProcess];
		System.out.println("\nPlease enter the following information about the following processes.");
		for(int i = 0; i < numProcess; i++)
		{
			System.out.println("\nProcess " + (i+1));
			System.out.print("\nArrival Time: ");
			int at = s.nextInt();
			System.out.print("\nBurst Time: ");
			int bt = s.nextInt();
			process[i] = new Process("P" + (i+1), bt, at);
		}
		Arrays.sort(process, new SortByArrival());
		System.out.print("\nPlease enter the quantum time.\nQuantum Time: ");
		int quantum = s.nextInt();
		double avgWT = 0, avgTAT = 0;
		int time = 0;
		while(true)
		{
			boolean done = true;
			for(int i = 0; i < numProcess; i++)
			{
				if(process[i].remBT > 0 && process[i].AT <= time)
				{
					done=false;
					if(process[i].remBT > quantum) 
					{
						time += quantum;
						process[i].remBT = process[i].remBT-quantum;
						System.out.println(i + " TIME " + time);
					}
					else
					{						
						time += process[i].remBT;
						process[i].WT = time - process[i].BT;
						process[i].remBT = 0;
						System.out.println(i + " TIME "+ time);
						process[i].CT = time;
						process[i].TAT = process[i].CT - process[i].AT;
						avgWT += process[i].WT;
						avgTAT += process[i].TAT;
					}
				}
			}
			if(done==true) 
			{
				break;
			}
		}
		System.out.println("\n\nPNO\tBT\tAT\tCT\tTAT\tWT\tPR");
		for(int i = 0; i < numProcess; i++)
		{
			process[i].display();
		}
		avgTAT /= numProcess;
		avgWT /= numProcess;
		System.out.println("Average WT: " + avgWT);
		System.out.println("Average TAT: " + avgTAT);
	}
}

