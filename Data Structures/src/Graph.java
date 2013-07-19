import java.util.ArrayList;


public class Graph <E extends Comparable<E>>{
	
	ArrayList<E> [] graph;
	E [] Objects;
	boolean isDirected;
	int nodes, edges;
	
	public Graph(int N, int M, boolean directed){
		nodes = N;
		edges = M;
		isDirected = directed;
		graph = new ArrayList[N];
		for (int i =0;i<N;i++){
			graph[i] = new ArrayList<E>();
		}
	}
	
	public Graph(int N, int M, int [][] connections, boolean directed){
		this(N, M, directed);
	}
	
	private void buildGraph(int [][] conn){
		int u, v;
		for (int i = 0;i<conn.length;i++){
			u = conn[i][0];
			v = conn[i][1];
			//graph[u].add(v);
			if (!isDirected){
				//graph[v].add(u);
			}
		}
	}
	
}
