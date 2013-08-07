import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;


public class PiecewiseLinearFunctionDiv2
{
	public int[] countSolutions(int[] Y, int[] q)
	{
		double[] slopes = new double [Y.length-1];
		double [] cs= new double [Y.length-1];
		for (int i=0;i<Y.length-1;i++){
			double x1 = i+1,x2=i+2,y1=Y[i],y2=Y[i+1];
			if (x2==x1){
				slopes[i] = -1;
				continue;
			}
			System.out.println(x1+" "+x2+" "+y1+" "+y2);
			slopes[i] = (((y2-y1)*1.0)/(x2-x1));
			cs[i] = y1-slopes[i]*x1;
		}
		for (int i=0;i<Y.length-1;i++)
			System.out.println(slopes[i]+" "+cs[i]);
		int [] sols = new int [q.length];
		for (int i=0;i<q.length;i++){
			int sum = 0;
			for (int j=0;j<cs.length;j++){
				int y = q[i];
				double pt = y-cs[j];
				if (slopes[j]==0){
					if (cs[j]==y){
						sum = -1;
						break;
					}
					else continue;
				}
				else if (slopes[j]==-1){
					if (Y[j]==y)
						sum++;
					continue;
				}
				pt/=slopes[j];
				System.out.println("PT "+pt+" "+j);
				if (pt>=j+1&&pt<=j+2&&(j==0||Y[j]!=q[i])){
					sum++;
				}
			}
			sols[i] = sum;
		}
		return sols;
	} 
}	
<%:testing-code%>
}
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!