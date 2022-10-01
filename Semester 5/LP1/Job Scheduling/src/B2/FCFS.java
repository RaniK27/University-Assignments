package B2; 

import java.util.*;
import java.util.Scanner;

public class FCFS 
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
		Arrays.sort(process,new SortByArrival());
		int sum = 0;
		double avgWT = 0, avgTAT = 0;
		System.out.println("\n\nPNO\tBT\tAT\tCT\tTAT\tWT");
		for(int i = 0; i < numProcess; i++)
		{
			sum = process[i].CT = sum + process[i].BT;
			process[i].TAT = process[i].CT - process[i].AT;
			process[i].WT = process[i].TAT - process[i].BT;
			avgWT += process[i].WT;
			avgTAT += process[i].TAT;
			process[i].display();
		}
		avgTAT /= numProcess;
		avgWT /= numProcess;
		System.out.println("Average WT: " + avgWT);
		System.out.println("Average TAT: " +avgTAT);
	}
}


