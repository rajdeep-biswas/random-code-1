import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		
		int[] right = {0, 1}, left = {0, -1}, up = {-1, 0}, down = {1, 0}, rightUp = {-1, 1}, leftUp = {-1, -1}, leftDown = {1, -1}, rightDown = {1, 1};
		
		int n = in.nextInt();
		int k = in.nextInt();
		int rq = in.nextInt() - 1;
		int cq = in.nextInt() - 1;
		
		int obs[][] = new int[k][2];
		
		for(int i = 0; i < k; i++)
			for(int j = 0; j < 2; j++)
				obs[i][j] = in.nextInt() - 1;
		
		int count = 0;
		
		// right
		for(int i = rq, j = cq; j < n; i += right[0], j += right[1]) {
			int f = 1;
			for(int l = 0; l < k; l++) {
				if(i == obs[l][0] && j == obs[l][1]) {
					f = 0;
					break;
				}
			}
			if(f == 0)
				break;
			count++;
			System.out.println("move right once");
		}
		
		// left
		for(int i = rq, j = cq; j > -1; i += left[0], j += left[1]) {
			int f = 1;
			for(int l = 0; l < k; l++) {
				if(i == obs[l][0] && j == obs[l][1]) {
					f = 0;
					break;
				}
			}
			if(f == 0)
				break;
			count++;
			System.out.println("move left once");
		}
		
		// up
		for(int i = rq, j = cq; i > -1; i += up[0], j += up[1]) {
			int f = 1;
			for(int l = 0; l < k; l++) {
				if(i == obs[l][0] && j == obs[l][1]) {
					f = 0;
					break;
				}
			}
			if(f == 0)
				break;
			count++;
			System.out.println("move up once");
		}
		
		// down
		for(int i = rq, j = cq; i < n; i += down[0], j += down[1]) {
			int f = 1;
			for(int l = 0; l < k; l++) {
				if(i == obs[l][0] && j == obs[l][1]) {
					f = 0;
					break;
				}
			}
			if(f == 0)
				break;
			count++;
			System.out.println("move down once");
		}
		
		// rightUp
		for(int i = rq, j = cq; i > -1 || j < n; i += rightUp[0], j += rightUp[1]) {
			int f = 1;
			for(int l = 0; l < k; l++) {
				if(i == obs[l][0] && j == obs[l][1]) {
					f = 0;
					break;
				}
			}
			if(f == 0)
				break;
			count++;
			System.out.println("move right up once");
		}
		
		// leftUp
		for(int i = rq, j = cq; i > -1 || j > -1; i += leftUp[0], j += leftUp[1]) {
			int f = 1;
			for(int l = 0; l < k; l++) {
				if(i == obs[l][0] && j == obs[l][1]) {
					f = 0;
					break;
				}
			}
			if(f == 0)
				break;
			count++;
			System.out.println("move left up once");
		}
	
		// leftDown
		for(int i = rq, j = cq; i < n || j > -1; i += leftDown[0], j += leftDown[1]) {
			int f = 1;
			for(int l = 0; l < k; l++) {
				if(i == obs[l][0] && j == obs[l][1]) {
					f = 0;
					break;
				}
			}
			if(f == 0)
				break;
			count++;
			System.out.println("move left down once");
		}
		
		// rightDown
		for(int i = rq, j = cq; i < n || j < n; i += rightDown[0], j += rightDown[1]) {
			int f = 1;
			for(int l = 0; l < k; l++) {
				if(i == obs[l][0] && j == obs[l][1]) {
					f = 0;
					break;
				}
			}
			if(f == 0)
				break;
			count++;
			System.out.println("move right down once");
		}
		
		System.out.println(count);
		
		in.close();
	}
}