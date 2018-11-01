#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
	int A[2]; // pipe A
	pipe(A);
	pid_t pid1 = fork(); // cat
	if (!pid1) {
		dup2(A[1], 1);
		close(A[0]);
		close(A[1]);
		execlp("cat","cat", "log.txt", NULL);
		exit(EXIT_FAILURE);
	}
	
	int B[2]; // pipe B
	pipe(B);
	pid_t pid2 = fork();                                       
	if (!pid2) { // cut
		dup2(A[0], 0);
		close(A[0]);
		close(A[1]); 

		dup2(B[1], 1);
		close(B[0]);
		close(B[1]);      

		execlp("grep","grep", "-e", "10/Oct/2006", NULL);
		exit(EXIT_FAILURE);                            
	}

	close(A[0]);
	close(A[1]);
	
	int C[2]; // pipe C
	pipe(C);
	
	pid_t pid3 = fork();                                       
	if (!pid3) { // sed
		dup2(B[0], 0);
		close(B[0]);
		close(B[1]);

		dup2(C[1], 1);
		close(C[0]);
		close(C[1]);

		execlp("sort","sort", "-k1", NULL); // 
		exit(EXIT_FAILURE);                            
	}
	
	close(B[0]);
	close(B[1]);

	int D[2]; // pipe D
	pipe(D);
	
	pid_t pid4 = fork();                                       
	if (!pid4) { // sed
		dup2(C[0], 0);
		close(C[0]);
		close(C[1]);

		dup2(D[1], 1);
		close(D[0]);
		close(D[1]);

		execlp("awk","awk", "{ if(address != $1){ print address,count; address = $1;count =1;} else{count ++;}}", NULL); // cat 
		exit(EXIT_FAILURE);                            
	}
	
	close(C[0]);
	close(C[1]);
	
	int E[2]; // pipe E
	pipe(E);
	
	pid_t pid5 = fork();                                       
	if (!pid5) { // sed
		dup2(D[0], 0);
		close(D[0]);
		close(D[1]);

		dup2(E[1], 1);
		close(E[0]);
		close(E[1]);

		execlp("sort","sort","-k2","-n", "-r", NULL); // cat 
		exit(EXIT_FAILURE);                            
	}
	
	close(D[0]);
	close(D[1]);
	
	int F[2]; // pipe F
	pipe(F);
	
	pid_t pid6 = fork();                                       
	if (!pid6) { // sed
		dup2(E[0], 0);
		close(E[0]);
		close(E[1]);

		dup2(F[1], 1);
		close(F[0]);
		close(F[1]);

		execlp("awk", "awk", "{ a+= $2; print a;}",NULL); // cat 
		exit(EXIT_FAILURE);                            
	}
	
	close(F[0]);
	close(F[1]);
	int G[2]; // pipe G
	pipe(G);
	
	pid_t pid7 = fork();                                       
	if (!pid7) { // sed
		dup2(F[0], 0);
		close(F[0]);
		close(F[1]);

		dup2(G[1], 1);
		close(G[0]);
		close(G[1]);

		execlp("sort","sort","-k1", "-n","-r",  NULL); // cat 
		exit(EXIT_FAILURE);                            
	}
	
	close(F[0]);
	close(F[1]);
	int H[2]; // pipe H
	pipe(H);
	
	pid_t pid8 = fork();                                       
	if (!pid8) { // sed
		dup2(G[0], 0);
		close(G[0]);
		close(G[1]);

		dup2(H[1], 1);
		close(H[0]);
		close(H[1]);

		execlp("head","head","-1",  NULL); // cat 
		exit(EXIT_FAILURE);                            
	}
	
	close(G[0]);
	close(G[1]);
	int K[2]; // pipe K
	pipe(K);
	
	pid_t pid9 = fork();                                       
	if (!pid9) { // sed
		dup2(H[0], 0);
		close(H[0]);
		close(H[1]);

		dup2(K[1], 1);
		close(K[0]);
		close(K[1]);

		execlp("awk","awk","{print $1}",  NULL); // 
		exit(EXIT_FAILURE);                            
	}
	
	close(H[0]);
	close(H[1]);
	int L[2]; // pipe L
	pipe(L);
	
	pid_t pid10 = fork();                                       
	if (!pid10) { 
		dup2(K[0], 0);
		close(K[0]);
		close(K[1]);

		dup2(L[1], 1);
		close(L[0]);
		close(L[1]);

		execlp("cat","cat","log.txt",  NULL); // cat 
		exit(EXIT_FAILURE);                            
	}
	
	close(K[0]);
	close(K[1]);
	int M[2]; // pipe M
	pipe(M);
	
	pid_t pid11 = fork();                                       
	if (!pid11) { // sed
		dup2(L[0], 0);
		close(L[0]);
		close(L[1]);

		dup2([1], 1);
		close(M[0]);
		close(M[1]);

		execlp("  NULL); // 
		exit(EXIT_FAILURE);                            
	}
	
	close(K[0]);
	close(K[1]);
	
    int N[2]; // pipe N
	pipe(N);
	pid_t pid12 = fork();                                       
	if (!pid12) { 
		dup2(M[0], 0);
		close(M[0]);
		close(M[1]); 

		dup2(N[1], 1);
		close(N[0]);
		close(N[1]);      

		execlp("grep","grep", "-e", "10/Oct/2006", NULL);
		exit(EXIT_FAILURE);                            
	}

	close(M[0]);
	close(M[1]);
	
	int O[2]; // pipe O
	pipe(O);
	
	pid_t pid13 = fork();                                       
	if (!pid13) { // sed
		dup2(N[0], 0);
		close(N[0]);
		close(N[1]);

		dup2(O[1], 1);
		close(O[0]);
		close(O[1]);

		execlp("sort","sort", "-k1", NULL); // 
		exit(EXIT_FAILURE);                            
	}
	
	close(N[0]);
	close(N[1]);

	int P[2]; // pipe P
	pipe(P);
	
	pid_t pid14 = fork();                                       
	if (!pid14) { // sed
		dup2(O[0], 0);
		close(O[0]);
		close(O[1]);

		dup2(P[1], 1);
		close(P[0]);
		close(P[1]);

		execlp("awk","awk", "{ if(address != $1){ print address,count; address = $1;count =1;} else{count ++;}}", NULL); // cat 
		exit(EXIT_FAILURE);                            
	}
	
	close(O[0]);
	close(O[1]);
	
	int R[2]; // pipe R
	pipe(R);
	
	pid_t pid15 = fork();                                       
	if (!pid15) { // sed
		dup2(P[0], 0);
		close(P[0]);
		close(P[1]);

		dup2(R[1], 1);
		close(R[0]);
		close(R[1]);

		execlp("sort","sort","-k2","-n", "-r", NULL); 
		exit(EXIT_FAILURE);                            
	}
	
	close(P[0]);
	close(P[1]);
	
	int S[2]; // pipe S
	pipe(S);
	
	pid_t pid16 = fork();                                       
	if (!pid16) { 
		dup2(R[0], 0);
		close(R[0]);
		close(R[1]);

		dup2(S[1], 1);
		close(S[0]);
		close(S[1]);

		execlp("head","head", NULL); 
		exit(EXIT_FAILURE);                            
	}
	
	close(R[0]);
	close(R[1]);
	
	int T[2]; 
	pipe(T);
	
	pid_t pid17 = fork();                                       
	if (!pid17) { // sed
		dup2(S[0], 0);
		close(S[0]);
		close(S[1]);

		dup2(T[1], 1);
		close(T[0]);
		close(T[1]);

		execlp("awk","awk","{ print $1,"-",$2,"-",$2/'$amount'*100;}", NULL); 
		exit(EXIT_FAILURE);                            
	}
	
	close(S[0]);
	close(S[1]);
	FILE* Cin = fdopen(C[0],"r"); // Cin is FILE* object made from C[0]
	int x,sum=0;
	while(fscanf(Cin,"%d",&x)>0){ // this loop is like the loop of shell 
		sum+=x;
	}
	printf("sum = %d\n",sum);
	
	
}	
	
