struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(0) {}
};

typedef struct ListNode ListNode;

#include<cstdio>
#include<cstdlib>
int main(){
	
	ListNode* p1 = (ListNode*)malloc(sizeof(ListNode));
	p1->val = 2;
	p1->next = 0;

	printf("p1->val = %d\n", p1->val);
	
  return 1;
}
