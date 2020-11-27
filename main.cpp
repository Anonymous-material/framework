#include"reduce.h"
#include"rnbp_a1_a2.h"
#include"paar.h"

void ReadTargetMatrix(uint64_t *NumInputs, uint64_t *NumTargets, uint64_t *Target, uint64_t *Dist, uint64_t *InitDist);

int SIZE;

mt19937 rand_generator;

int main(int argc, char *argv[])
{	
	uint64_t NumInputs = 0;
    uint64_t NumTargets = 0;
	uint64_t Target[MaxBaseSize] = {0};
	uint64_t Dist[MaxBaseSize] = {0};
	uint64_t InitDist[MaxBaseSize] = {0};
	
	ReadTargetMatrix(&NumInputs, &NumTargets, Target, Dist, InitDist);

 	rand_generator.seed(time(0));
    uniform_int_distribution<int> rand_distribution(0, 5);
    int OPTION_A = rand_distribution(rand_generator);
	
	vector<list> seq;
	(NumTargets < NumInputs)? SIZE = NumInputs : SIZE = NumTargets;
	
	for(int i = 0; i < SIZE; i++)
	{
		list tmp;
		tmp.value.push_back(i);
		tmp.flag = -1;
		tmp.usd = 0;
		seq.push_back(tmp); 
	 }

    switch(OPTION_A)
    {
		case 0: paar_algorithm1(seq, NumInputs, NumTargets, Target); break;
		case 1: rpaar_algorithm1(seq, NumInputs, NumTargets, Target); break;
		case 2: BP_algorithm(seq, NumInputs, NumTargets, Target, Dist); break;
		case 3: A1_A2_RNBP_algorithm(seq, NumInputs, NumTargets, 3, Target, Dist, InitDist); break;
		case 4: A1_A2_RNBP_algorithm(seq, NumInputs, NumTargets, 4, Target, Dist, InitDist); break;
		case 5: A1_A2_RNBP_algorithm(seq, NumInputs, NumTargets, 5, Target, Dist, InitDist); break;
		default:printf("error\n"); break;
    }
 	get_reduced(seq);
 	return 0;
}

void ReadTargetMatrix(uint64_t *NumInputs, uint64_t *NumTargets, uint64_t *Target, uint64_t *Dist, uint64_t *InitDist)
{	uint64_t N_in = 0;
	uint64_t N_out = 0;
    cin >> N_out;
    cin >> N_in;
    *NumInputs = N_in;
    *NumTargets = N_out;
    int bit;
    for (int i = 0; i < *NumTargets; i++) 
    {
        uint64_t PowerOfTwo  = 1;
        Target[i] = 0;
        Dist[i] = -1; //initial distance from Target[i] is Hamming weight - 1
        for (int j = 0; j < *NumInputs; j++) 
        {
            cin >> bit;
            if (bit) 
            {	
            	Dist[i]++; //after using randomly permutation, change the Dist[]!!!!!!;
                Target[i] = Target[i] + PowerOfTwo;
            }
            PowerOfTwo = PowerOfTwo << 1;
        }
    }
    for (int k = 0; k < *NumInputs; k++) InitDist[k] = Dist[k];
}

void write_file(vector<list> seq)
{
	ofstream f;
	f.open("reduced_result_20201130.txt");
	f << "Xor Count = " << seq.size()-SIZE << endl;
	for(int i = SIZE; i < seq.size(); i++)
	{ 
		f<<"t["<<seq[i].value[0]<<"] = t["<<seq[i].value[1]<<"] ^ t["<<seq[i].value[2]<<"]";
		if(seq[i].flag >= 0)
		{
			f<<"    y["<<seq[i].flag<<"]";
		}
		f<<endl;
	}
	f.close();
}
