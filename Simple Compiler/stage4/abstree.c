struct Tnode *TreeCreate(int TYPE,int NODE,char* NAME,int VALUE,struct Tnode *ArgList,
										struct Tnode *Ptr1,struct Tnode *Ptr2,struct Tnode *Ptr3)
{
	struct Tnode * temp;
	temp = (struct Tnode *) malloc(sizeof(struct Tnode));
	temp -> TYPE = TYPE;
	temp -> NODE = NODE;
	temp -> NAME = NAME;
	temp -> VALUE =  VALUE;
	temp -> ArgList = ArgList;
	temp -> Ptr1 = Ptr1;
	temp -> Ptr2 = Ptr2;
	temp -> Ptr3 = Ptr3;
	return temp;
}

int Evaluate(struct Tnode *root)
{
	/*printf("Evaluate %d\n",root -> NODE);*/
	int number;
	if(root -> NODE == NODE_NUM)
	{
		/*printf("NODE_NUM\n");*/
		return (root -> VALUE); 
	}
	
	if(root -> NODE == NODE_ID)
	{
		/*printf("NODE_ID\n");*/
		if(value[*(root -> NAME)- 'a'] == NULL)
		{
			printf("un initialized variable\n");
			exit(1);
		}
		return *value[*(root -> NAME)- 'a'];							
	}
	struct  Tnode *temp ,*head;
	if(root -> NODE == DEFAULT)
	{
		Evaluate(root->Ptr1);
		Evaluate(root->Ptr2);
	}
	else
	{
	    temp=root;
		switch(temp -> NODE)
		{
			case NODE_PLUS :
									/*printf("---PLUS---");*/
				 					return (Evaluate(temp -> Ptr1) + Evaluate(temp -> Ptr2));
									break;
 			case NODE_MINUS :
 									/*printf("---MINUS---");*/
									return (Evaluate(temp -> Ptr1) - Evaluate(temp -> Ptr2));
									break;
 			case NODE_MUL :
 									/*printf("---MUL---");*/
									return (Evaluate(temp -> Ptr1) * Evaluate(temp -> Ptr2));
									break;
			case NODE_LT  :
									/*printf("---LT---");*/
									if(Evaluate(temp -> Ptr1) < Evaluate(temp -> Ptr2))
									{
										return TRUE;
									}
									else
										return FALSE;
									break;
			case NODE_GT  :
									/*printf("---GT---");*/
									if(Evaluate(temp -> Ptr1) > Evaluate(temp -> Ptr2))
									{
										return TRUE;
									}
									else
										return FALSE;
									break;
			case NODE_DEQ  :
									/*printf("---DEQ---");*/
									if(Evaluate(temp -> Ptr1) == Evaluate(temp -> Ptr2))
									{
										return TRUE;
									}
									else
										return FALSE;
									break;
			case NODE_ASGN :
								   if(value[*(temp -> Ptr1 -> NAME) -'a'] == NULL)
									{
									    value[*(temp -> Ptr1 -> NAME) - 'a'] = malloc(sizeof(int));
									}
									number = Evaluate(temp -> Ptr2);
									*value[*(temp -> Ptr1 -> NAME)- 'a'] = number;
									/*printf("---ASGN---");*/
									/*printf("%c is %d\n",*(temp -> Ptr1 -> NAME),*value[*(temp -> Ptr1 -> NAME)- 'a']);*/
									break;
			case NODE_READ :
									/*printf("---READ---");*/
									printf("Enter a number : ");
									if(value[*(temp -> Ptr2 -> NAME)-'a'] == NULL)
									{
									    value[*(temp -> Ptr2 -> NAME) - 'a'] = malloc(sizeof(int));
									}
									scanf("%d",value[*(temp -> Ptr2 -> NAME)-'a']);
									/*printf("%c is %d\n",*(temp -> Ptr2 -> NAME),*value[*(temp -> Ptr2 -> NAME)- 'a']);*/
									break;
			case NODE_WRITE :
									/*printf("---WRITE---");*/
									number = Evaluate(temp -> Ptr2);
									printf("%d\n",number);
									break;
			case NODE_IF  :
									/*printf("---IF---");*/
									number = Evaluate(temp -> Ptr1);
									if(number == TRUE)
									{
										number = Evaluate(temp -> Ptr2);
									}
									break;
			case NODE_IF_ELSE:
									/*printf("---IF_ELSE---");*/
									number = Evaluate(temp -> Ptr1);
									if(number == TRUE)
									{
										number = Evaluate(temp -> Ptr2);
									}
									else
										number = Evaluate(temp -> Ptr3);
									break;
		 	case NODE_WHILE :
		 							/*printf("---WHILE----");*/
		 							number = Evaluate(temp -> Ptr1);
		 							while(number == TRUE)
		 							{
		 								number = Evaluate(temp -> Ptr2);
		 								number = Evaluate(temp -> Ptr1);
		 							}
		 							break;
			default:
					printf("NODETYPE is %d\n",temp -> NODE);
					printf("Error : Unknown Node Type\n");
					exit(1);	
					}														
		}
		
	return 0;
}

