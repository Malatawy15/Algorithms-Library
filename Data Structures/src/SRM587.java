
public class SRM587 {
	public static String canTransform(String init, String goal){
		while(goal.contains("z"))
			goal.replace("z", "");
		if (goal.compareTo(init)==0)
			return "Yes";
		else return "No";
		int [] ci, cg;
		ci = new int [26];
		cg = new int [26];
		if (goal.length()<init.length())
			return "No";
		int j = 0;
		for (int i=0;i<goal.length();i++)
			if (j==init.length()&&)
			if (init.charAt(i)==goal.charAt(j)){
				j++;
			}
		return j==goal.length()?"Yes":"No";
	}
}
