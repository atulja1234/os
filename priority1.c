#include<stdio.h>
#include<stdlib.h>
struct process{
	int id;
	int priority;
	int arrival_time;
	int burst_time;
	int timer;
	int wait;
	int tat;
};
int n; 
typedef struct process process;
int h_p(process pr[], int n){
    int i;
    int hp = 0;
    for(i=0;i<n;i++){
        if((pr[i].priority < pr[hp].priority) && (pr[i].burst_time > 0)){
            hp = i;
        }
    }
    for(i=0;i<n;i++){
        if((pr[i].priority == pr[hp].priority) && (pr[i].burst_time > 0)){
            if(pr[i].id < pr[hp].id)
                hp = i;
        }
    }
    return hp;
}
void update_process(process a[],int n,int rp){
    int i;
    printf("Inside update n is %d",n);
    for(i=0; i<n; i++){
        if(a[i].burst_time>0){
                if(i!=rp){
                    a[i].wait++;
                    if(a[i].timer>0){
                        a[i].timer--;
                    }
                    else{
                        a[i].timer = 2;
                        a[i].priority -= 1;
                        if(a[i].priority < 0)
                            a[i].priority = 0;
                    }
                }
                else if(i == rp){
                    a[i].burst_time--;
                }
        }
    }
}
int count_done_process(process a[],int n){
    int i;
    int c=0;
    for(i=0; i<n; i++){
        if(a[i].burst_time == 0){
            c++;
        }
    }
    return c;
}
int main(){
	printf("Enter number of process: ");
	scanf("%d",&n);
	struct process p[n];
	int i;
	for(i=1; i<=n; i++){
		p[i-1].id = i;
		p[i-1].timer = 2;
		p[i-1].wait = 0;
		p[i-1].tat = 0;
		printf("Enter arrival time of the process %d: ",i);
		scanf("%d",&p[i-1].arrival_time);
		printf("Enter priority of process %d: ",i);
		scanf("%d",&p[i-1].priority);
		printf("Enter burst time of process %d: ",i);
		scanf("%d",&p[i-1].burst_time);
	}
	int j;
	struct process temp;
	for(i=0; i<n-1; i++){
		for(j=0; j<n-i-1; j++){
			if(p[j].arrival_time > p[j+1].arrival_time){
				temp = p[j];
				p[j]= p[j+1];
				p[j+1] = temp;
			}
		}
	}
	for(i=0; i<n; i++){
		printf("process id=%d, arrival time=%d, burst time=%d, priority=%d\n",p[i].id,p[i].arrival_time,p[i].burst_time,p[i].priority);
	}
	struct process curr[n];
	int clock = 0;
    int p_cur = 0;
    int c_cur = 0;
    int rp = -1;
    int dp = 0;
    int pp;
	while(p_cur < n){
            while(p_cur < n && p[p_cur].arrival_time <= clock){
                curr[c_cur] = p[p_cur];
                p_cur++;
                c_cur++;
            }
            pp = h_p(curr, c_cur);
            if(rp == -1){
                rp = pp;
                clock++;
                update_process(curr,c_cur,rp);
            }
            else{
                clock +=2;
            }
            dp = count_done_process(curr, c_cur);
	}
    for(i=0; i<n; i++){
                printf("process id=%d, arrival time=%d, burst time=%d, priority=%d\n",curr[i].id,curr[i].arrival_time,curr[i].burst_time,curr[i].priority);
            }
}

