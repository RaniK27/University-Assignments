package B2;

import java.util.*;

public class SJF 
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
		int min = Integer.MAX_VALUE;
		int count = 0, shortest = 0;
		int time = 0;
		int sum = 0;
		double avgWT = 0, avgTAT = 0;
		boolean check = false;
		System.out.println("\n\nPNO\tBT\tAT\tCT\tTAT\tWT");
		while (count < numProcess) 
		{
			for (int i = 0; i < numProcess; i++) 
			{
				if(process[i].AT <= time && (process[i].remBT < min && process[i].remBT > 0)) 
				{
					shortest = i;
					min = process[i].remBT;
					check = true;
				}
			}
			if (check == false) 
			{
				time++;
				continue;
			}
			process[shortest].remBT--;
			min = process[shortest].remBT;
			if (min == 0) 
			{
				min = Integer.MAX_VALUE;
				count++;
				sum = time + 1;
				process[shortest].CT = sum;
				process[shortest].TAT = process[shortest].CT - process[shortest].AT;
				process[shortest].WT = process[shortest].TAT - process[shortest].BT;
				avgWT += process[shortest].WT;
				avgTAT += process[shortest].TAT;
				process[shortest].display();
			}
			time++;
		}
		avgTAT /= numProcess;
		avgWT /= numProcess;
		System.out.println("Average WT: " + avgWT);
		System.out.println("Average TAT: " + avgTAT);
	}
}
