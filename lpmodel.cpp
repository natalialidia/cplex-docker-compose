#include <ilcplex/ilocplex.h>
ILOSTLBEGIN

int
main ()
{
    IloEnv   env;
    try {
        IloModel model(env);

        IloNumVarArray x(env);
        IloRangeArray c(env);

        x.add(IloNumVar(env, 0.0));
        x.add(IloNumVar(env, 0.0));
        x.add(IloNumVar(env, 0.0));

        model.add(IloMaximize(env, x[0] + 7 * x[1]));

        c.add(x[0] +  7 * x[1] +     x[2] ==   9);
        c.add(x[0] + 14 * x[1] + 2 * x[2] >= -1);
        c.add(x[0] +  7 * x[1] +     x[2] >=  7);

        x[0].setName("x1");
        x[1].setName("x2");
        x[2].setName("x3");

        c[0].setName("c1");
        c[1].setName("c2");
        c[2].setName("c3");
        model.add(c);

        IloCplex cplex(model);
        cplex.exportModel("model.lp");

        // Optimize the problem and obtain solution.
        if ( !cplex.solve() ) {
            env.error() << "Failed to optimize LP" << endl;
            throw(-1);
        }

        IloNumArray vals(env);
        env.out() << "Solution status = " << cplex.getStatus() << endl;
        env.out() << "Solution value  = " << cplex.getObjValue() << endl;
        cplex.getValues(vals, x);
        env.out() << "Values        = " << vals << endl;
        cplex.getSlacks(vals, c);
        env.out() << "Slacks        = " << vals << endl;
        cplex.getDuals(vals, c);
        env.out() << "Duals         = " << vals << endl;
        cplex.getReducedCosts(vals, x);
        env.out() << "Reduced Costs = " << vals << endl;
    }
    catch (IloException& e) {
        cerr << "Concert exception caught: " << e << endl;
    }
    catch (...) {
        cerr << "Unknown exception caught" << endl;
    }

    env.end();

    return 0;
}