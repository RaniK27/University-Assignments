package B2;

import java.util.*;

public class Priority
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
			System.out.print("\nPriority: ");
			int priority=s.nextInt();
			process[i] = new Process("P" + (i+1), bt, at, priority);
		}
		Arrays.sort(process, new SortByPriority());
		int sum = 0;
		double avgWT = 0, avgTAT = 0;
		System.out.println("\n\nPNO\tBT\tAT\tCT\tTAT\tWT\tPR");
		for(int i = 0; i < numProcess; i++)
		{
			sum = process[i].CT = sum + process[i].BT;
			process[i].TAT = process[i].CT - process[i].AT;
			process[i].WT = process[i].TAT - process[i].BT;
			if(process[i].WT < 0)
			{
				process[i].WT = 0;
			}
			avgWT += process[i].WT;
			avgTAT += process[i].TAT;
			process[i].display2();
		}
		avgTAT /= numProcess;
		avgWT /= numProcess;
		System.out.println("Average WT: "+avgWT);
		System.out.println("Average TAT: "+avgTAT);
	}
}
