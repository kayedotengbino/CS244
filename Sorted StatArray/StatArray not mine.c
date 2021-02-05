StatArray newStatArray(){
    StatArray s = (StatArray) malloc(sizeof(struct stat));
    s->items = (int*) malloc(sizeof(int)*10);
    s->count = 0;
    s->size = 10;
    return s;
}
void destroy(StatArray *s){
    free((*s)->items);
    free(*s);
    *s = NULL;
}
int doubleTheSize(StatArray s){
    int *temp;
    int multiplier =2;
    int success = 0;
    temp = (int*)malloc(sizeof(int)*s->size*multiplier);
    
    if(temp!=NULL){
        s->size *= multiplier;
            for(int i=0;i<s->count;i++)
                temp[i] = s->items[i];

                free(s->items);
                s->items = temp;
                success = 1;
    }
    return success;
}
void addLast(StatArray s, int elem){
    if((s->count < s->size) || doubleTheSize(s))
        s->items[s->count++] = elem;
}
void add(StatArray s, int elem){
    int temp;
    addLast(s,elem);

            //sort
            if(s->count > 0){
                for(int i=0; i<s->count;i++){
                    for(int j=i+1; j<s->count;j++){
                        if(s->items[i] > s->items[j]){
                            temp = s->items[i];
                            s->items[i] = s->items[j];
                            s->items[j] = temp;
                        }
                    }
                }
            }
    
}

void display(const char *name,const StatArray s){
    printf("%s = [ ",name);
    for(int i=0;i<s->count;i++)
        printf("%d ",s->items[i]);
    
    printf("]\n");
}
void clear(StatArray s){
    s->count = 0;
}
int isEmpty(const StatArray s){
    return s->count == 0;
}
int getCount(const StatArray s){
    return (s->count);
}

int findSum(const StatArray s){
    int sum = 0;
    for(int i = 0; i < s->count; i++){
        sum += s->items[i];
    }
    return sum;
}

float findMean(const StatArray s){
    return (float)findSum(s)/(float)s->count;
}
float findStandardDeviation(const StatArray s){
    float sum = 0;
    float p = 0;
    float mean = findMean(s);
    float n = s->count-1;

    for(int i=0;i<s->count;i++){
        p = pow(s->items[i] - mean, 2);
        sum += p;
        p=0;
    }
    return sqrt((float)sum/n);
}
int contains(StatArray s, int elem){
    for(int i=0;i<s->count;i++){
        if(s->items[i] == elem)
        return 1;
    }
    return 0;
}
int frequency(StatArray s, int elem){
    int freq = 0;
    for(int i=0;i<s->count;i++){
        if(s->items[i] == elem)
        freq++;;
    }
    return freq;
}
int findMin(const StatArray s){
    int min = s->items[0];
    for(int i=0;i<s->count;i++){
        if(s->items[i] < min)
            min = s->items[i];
    }
    return min;
}
int findMax(const StatArray s){
    int max = s->items[0];
    for(int i=0;i<s->count;i++){
        if(s->items[i] > max)
            max = s->items[i];
    }
    return max;
}
int findRange(const StatArray s){
    return findMax(s) - findMin(s);
}
float findMedian(const StatArray s){
    int temp;
    for(int i = 0; i<s->count-1; i++){
        for(int j = i+1; j<s->count; j++){
            if(s->items[j] < s->items[i]){
                temp = s->items[i];
                s->items[i] = s->items[j];
                s->items[j] =temp;
            }
        }
    }
    if(s->count%2==0){
        return ((s->items[s->count/2] + s->items[s->count/2-1])/2.0);
    }else{
        return (s->items[s->count/2]);
    }
}
int findPos(StatArray s, int x){
    int pos = -1;
    for(int i=0;i<s->count; i++){
        if(s->items[i] == x){
            pos = i;
            break;
        }
    }
    return pos;
}
void removeFirst(StatArray s, int x){
    int pos = findPos(s,x);
    if(pos != -1){
        for(int i = pos; i<s->count-1; i++)
                s->items[i] = s->items[i+1];
                
            s->count--;
    }
}
void removeAll(StatArray s, int x){
    for(int i=0; i<s->count;i++){
      removeFirst(s,x);
    }
}
