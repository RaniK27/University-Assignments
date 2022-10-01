package B2;

import java.util.Scanner;

public class Scheduling 
{
	public static void main(String[] args) 
	{
		System.out.println("Job Scheduling");
		char ch = 'Y';
		Scanner s = new Scanner(System.in);
		do
		{
			System.out.println("\nSNO.\tOption");
			System.out.println(" 1. \tFCFS");
			System.out.println(" 2. \tSJF");
			System.out.println(" 3. \tPriority");
			System.out.println(" 4. \tRound Robin");
			System.out.println(" 5. \tExit");
			System.out.print("\nPlease enter an option.\nOption: ");
			int op = s.nextInt();
			switch(op) 
			{
			case 1: 
				System.out.println("\nOPTION 1: FCFS\n");
				FCFS fcfs=new FCFS();
				fcfs.execute();
				break;
			case 2:
				System.out.println("\nOPTION 2: SJF\n");
				SJF sjf=new SJF();
				sjf.execute();
				break;
			case 3:
				System.out.println("\nOPTION 3: Priority\n");
				Priority pr=new Priority();
				pr.execute();
				break;
			case 4:
				System.out.println("\nOPTION 4: Round Robin\n");
				RR rr = new RR();
				rr.execute();
				break;
			case 5:
				System.out.println("\nOPTION 5: Exit\n");
				System.out.println("Exiting...");
				return;
			default:
				System.out.println("Invalid Input");
				break;
			}
			System.out.println("Do you want to continue? (Y/N)");
			ch = s.next().charAt(0);
		} while(ch == 'Y' || ch == 'y');	
	}
}
