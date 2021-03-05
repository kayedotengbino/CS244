/**
 * Author:     Michael S. Walker (mwalk762@mtroyal.ca).
 * Instructor: Marc Schroeder.
 * Date:       February 1 2019.
 * Course:     COMP 3649 – Programming Paradigms winter 2019
 *
 * Mount Royal University
 * - Department of Mathematics and Computing.
 *
 * Description: Given a valid 3-CNF expression, finds a truth assignment (or partial truth assignment) which satisfies
 * a boolean expression or, reports that the formula is unsatisfiable.
 *
 * Examples of Usage:
 *
 * $ make all
 * $ ./solve
 * (a + b + c) (a' + b' + c) ( a' + b + c' ) ( a' + b + c) ( z + p + q)
 * satisfiable by [a=false, b=true, z=true]
 * $ (EOF).
 */

int init_sat_solver (void);
void print_sat (FORMULA *bf, int is_sat);

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCDFAInspection"

int main (int argc, char **argv)
{
	init_sat_solver ();
}

/**
 * init_sat_solver:
 *
 * Initialize's fields.
 *
 * @return Returns (1) True if successful, otherwise (0) false.
 */

int init_sat_solver (void)
{
	void *clause_storage = malloc (__OR_OF_N_LITERALS);
	int  was_formula_built;

	FORMULA boolean_formula;

	boolean_formula.first = (CNF *) &boolean_formula;
	boolean_formula.last  = (CNF *) &boolean_formula;

	add_clause (clause_storage, &boolean_formula);
	was_formula_built = track_matching (boolean_formula.first, &boolean_formula);
	print_sat (&boolean_formula, was_formula_built);

	if (was_formula_built > -1)
	{
		destroy_list (&boolean_formula);
	}

	free (clause_storage);

	return was_formula_built;
}

/**
 * print_sat:
 *
 * In the case of unsatisfiability, the function prints "unsatisfiable". Otherwise, the program prints one
 * satisfying truth assignment (or partial assignment).
 *
 * @param is_sat a flag the tells if (-1) empty string (1) sat found (0) no sat found.
 * @param bf the boolean formula, this should contain the data needed for SAT.
 */

void print_sat (FORMULA *bf, int is_sat)
{
	char sat_list[__ASCII];
	int  neg_flag[__ASCII];
	int  upper;
	int  lower;
	int  index;
	int  n_lit;

	puts("\n");
	if (is_sat != 0)
	{
	    printf ("satisfiable by [");
		if (is_sat != -1)
		{
			for (upper = 'A', lower = 'a', n_lit = 0; lower < __ASCII; lower++, upper++)
			{
				if (bf->sat_list[upper] != 0)
				{
					neg_flag[n_lit] = true;
					sat_list[n_lit] = (char) tolower (upper);
					n_lit++;
				}
				if (bf->sat_list[lower] != 0)
				{

					neg_flag[n_lit] = false;
					sat_list[n_lit] = (char) lower;
					n_lit++;
				}
			}

			index = 0;
			while (n_lit > 0)
			{
				printf ("%c=%s%s", sat_list[index], neg_flag[index] != 0
				                                    ? "false"
				                                    : "true", n_lit == 1
				                                              ? "]"
				                                              : ", ");
				index++;
				n_lit--;
			}
		}
		else
		{
			printf (" ]");
		}
	}
	else
	{
		printf ("unsatisfiable");
	}
	puts("\n");
}

#pragma clang diagnostic pop
