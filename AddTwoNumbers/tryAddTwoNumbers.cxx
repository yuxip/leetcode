/*You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

/*
* Definition for singly-linked list.
*/
#include<cstdio>
#include<cstdlib>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

//typedef struct ListNode ListNode;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
	
	if(!l1&&!l2) return 0;
        if(!l1)return l2;
        if(!l2)return l1;
	
	ListNode* q1 = l1; ListNode* q2 = l2;
        ListNode* q1pre = 0;
        bool increment = false;
        while(q1){
		
		int sum = q1->val;
                if(q2)sum += q2->val;

                if(increment){
			sum += 1;
                        increment = false;
                }

                if(sum>=10){
                        sum = sum%10;
                        increment = true;
                }
		
		q1->val = sum;
		
		q1pre = q1;
                q1 = q1->next;
                if(q2)q2 = q2->next;

        }
	
	while(q2){
                q1pre->next = q2;
                int sum = q2->val;
                if(increment){
                        sum += 1;
                        increment = false;
                }

                if(sum >= 10){
                        sum = sum%10;
                        increment = true;
                }
                q2->val = sum;
                q1pre = q2;
                q2 = q2->next;

        }
	
	if(increment){
		ListNode* ladd = new ListNode(0);
                if(!ladd){ return 0;}
                ladd->val = 1;
                q1pre->next = ladd;
        }

        return l1;
 }


//test
int main(){
	
	//build ListNode l1
	ListNode* l1 = NULL;
	ListNode* lp1 = NULL;
	const int nnode1 = 1;
	int p1[nnode1] = {6};
	for(int i = 0; i < nnode1; i++){
		
		ListNode* tmpl1 = new ListNode(0);
		if(!tmpl1){ printf("not enough memory!!"); return 0;}	
		tmpl1->val = p1[i];
		if(i == 0){
			l1 = tmpl1;
			lp1 = l1;
		}
		else{
			lp1->next = tmpl1;
			lp1 = tmpl1;
		}
		
	}
	
	printf("l1: ");
	lp1 = l1;
	while(lp1){
		
		int val = lp1->val;
                if(lp1->next)printf("%d->",val);
		else printf("%d",val);
		lp1 = lp1->next;	
	}
	printf("\n");
	
	//build ListNode l2
	ListNode* l2 = NULL;
        ListNode* lp2 = NULL;
        const int nnode2 = 1;
        int p2[nnode2] = {8};
        for(int i = 0; i < nnode2; i++){
		
		ListNode* tmpl2 = new ListNode(0);
                if(!tmpl2){ printf("not enough memory!!"); return 0;}
                tmpl2->val = p2[i];
                if(i == 0){
                        l2 = tmpl2;
                        lp2 = l2;
                }
                else{
                        lp2->next = tmpl2; 
                        lp2 = tmpl2;
                }
                
        }

        printf("l2: ");
        lp2 = l2;
        while(lp2){

                int val = lp2->val;
                if(lp2->next)printf("%d->",val);
		else printf("%d",val);
                lp2 = lp2->next;
        }
        printf("\n");

	
	//add l1 and l2;
	ListNode* ladd = addTwoNumbers(l1,l2);
	//print ladd
	printf("ladd: ");
        ListNode* lpadd = ladd;
        while(lpadd){

                int val = lpadd->val;
                if(lpadd->next)printf("%d->",val);
		else printf("%d",val);
                lpadd = lpadd->next;
        }
        printf("\n");
	
	return 1;
  }

        
