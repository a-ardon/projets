import java.util.Random; 
import java.util.ArrayList;

public class kill_processes
{
	public static Random r = new Random();

	public static boolean already_present(ArrayList<Integer> arr, int element, int current_index)
	{
		for(int i = 0; i < current_index; i++)
		{
			if(arr.get(i) == element)
			{
				return true;
			}
		}
		return false;
	}

	public static void f_ppids(ArrayList<Integer> ppids, int size_arr)
	{
		int i = 0;
		int to_add = r.nextInt(10);
		for(i = 0; i < size_arr; i++)
		{
			if(i == 0)
			{
				ppids.add(to_add);
			}
			else
			{
				to_add = r.nextInt(10);
				while(already_present(ppids,to_add,i) == true)
				{
					to_add = r.nextInt(10);
				}
				ppids.add(to_add);
			}
		}
	}

	public static void f_pids(ArrayList<Integer> pids, ArrayList<Integer> ppids, int size_arr)
	{
		int i = 0;
		int to_add = r.nextInt(13);
		for(i = 0; i < size_arr; i++)
		{
			if(i == 0)
			{
				while(to_add <= ppids.get(i))
				{
					to_add = r.nextInt(13);
				}
				pids.add(to_add);
			}
			else
			{
				to_add = r.nextInt(13);
				while((already_present(pids,to_add,i) == true) || (to_add <= ppids.get(i)))
				{
					to_add = r.nextInt(13);
				}
				pids.add(to_add);
			}
		}
	}

	public static void checks_interdependances(ArrayList<Integer> ppids, ArrayList<Integer> pids, int size_arr, ArrayList<Integer> who_to_kill, int index_of_who_to_kill)
	{
		int check = 0;
		for(int i = 0; i < size_arr; i++)
		{
			if(i != index_of_who_to_kill && ppids.get(i) == pids.get(index_of_who_to_kill))
			{
				check++;
				who_to_kill.add(ppids.get(index_of_who_to_kill));
				checks_interdependances(ppids,pids,size_arr,who_to_kill,i);
			}
		}
		if(check == 0)
		{
			who_to_kill.add(ppids.get(index_of_who_to_kill));
			who_to_kill.add(pids.get(index_of_who_to_kill));
		}
	}

	public static ArrayList<Integer> returns_who_to_kill(ArrayList<Integer> ppids, ArrayList<Integer> pids, int size_arr, int index_of_who_to_kill)
	{
		ArrayList<Integer> who_to_kill = new ArrayList<Integer>();
		checks_interdependances(ppids,pids,size_arr,who_to_kill,index_of_who_to_kill);
		return who_to_kill;
	}

	public static void main(String[] args)
	{
		int size_arr = 6;
		ArrayList<Integer> ppids = new ArrayList<Integer>();
		ArrayList<Integer> pids = new ArrayList<Integer>();
		f_ppids(ppids,size_arr);
		f_pids(pids,ppids,size_arr);
		System.out.println("ppids : " + ppids);
		System.out.println("pids  : " + pids);
		int index_of_who_to_kill = r.nextInt(size_arr);
		System.out.printf("ppid a tuer : %d | pid fils du ppid : %d\n",ppids.get(index_of_who_to_kill),pids.get(index_of_who_to_kill));
		System.out.println(returns_who_to_kill(ppids,pids,size_arr,index_of_who_to_kill));
	}
}