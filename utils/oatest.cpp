
/** \file oatest.cpp

C++ program: oatest

oatest: tool for testing new algorithms

Author: Pieter Eendebak <pieter.eendebak@gmail.com>, (C) 2014

Copyright: See LICENSE.txt file that comes with this distribution
*/

#include <algorithm>
#include <iostream>
#include <map>
#include <stdio.h>
#include <stdlib.h>

#include "anyoption.h"
#include "arrayproperties.h"
#include "arraytools.h"
#include "extend.h"
#include "graphtools.h"
#include "unittests.h"
#include "tools.h"

#include "evenodd.h"
#include "lmc.h"

#include "conference.h"

#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/LU>
#include <Eigen/SVD>

#include "Deff.h"
#include "arraytools.h"
#include "strength.h"

#ifdef HAVE_BOOST
#include <boost/filesystem.hpp>
#include <string>
#endif

using namespace Eigen;


#include "graphtools.h"


/// show information about Pareto criteria for conference matrix
void paretoInfo (const array_link &alx) {
        std::vector< int > j5 = alx.Jcharacteristics (5);
        int j5max = vectormax (j5, 0);

        int v1 = (j5max == alx.n_rows);
        int v2 = 1 - v1;

        int N = alx.n_rows;
        int rank = array2xf (alx).rank ();
        std::vector< int > F4 = alx.Fvalues (4);
        std::vector< double > gwlp = alx.GWLP ();
        printf ("pareto data: %d ; ", rank);
        printf (" %d ", (int)(N * N * gwlp[4]));
        printf (" ; ");
        display_vector (F4);
        printf (" ; ");
        printf (" %d ; %d", v1, v2);
        printf ("\n");
}

/// check whether an array is contained in a Pareto set
int arrayInPareto (const Pareto< mvalue_t< long >, array_link > &pset, const array_link &al, int verbose = 1) {

        std::vector< array_link > llx = pset.allindices ();
        arraylist_t ll (llx.begin (), llx.end ());
        int jx = arrayInList (al, ll, 0);
        if (verbose)
                myprintf ("arrayInPareto: index in pareto list %d\n", jx);
        return jx;
}


int main (int argc, char *argv[]) {
        AnyOption opt;
        /* parse command line options */
        opt.setFlag ("help", 'h'); /* a flag (takes no argument), supporting long and short form */
        opt.setOption ("output", 'o');
        opt.setOption ("input", 'I');
        opt.setOption ("rand", 'r');
        opt.setOption ("verbose", 'v');
        opt.setOption ("ii", 'i');
        opt.setOption ("jj");
        opt.setOption ("xx", 'x');
        opt.setOption ("dverbose", 'd');
        opt.setOption ("rows");
        opt.setOption ("cols");
        opt.setOption ("nrestarts");
        opt.setOption ("niter");
        opt.setOption ("mdebug", 'm');
        opt.setOption ("oaconfig", 'c'); /* file that specifies the design */

        opt.addUsage ("Orthonal Array: oatest: testing platform");
        opt.addUsage ("Usage: oatest [OPTIONS] [FILE]");
        opt.addUsage ("");
        opt.addUsage (" -h --help  			Prints this help ");
        opt.processCommandArgs (argc, argv);

        double t0 = get_time_ms (), dt = 0;
        int randvalseed = opt.getIntValue ('r', 1);
        int ix = opt.getIntValue ('i', 1);
        int r = opt.getIntValue ('r', 1);
        int jj = opt.getIntValue ("jj", 5);

        int xx = opt.getIntValue ('x', 0);
        int niter = opt.getIntValue ("niter", 10);
        int verbose = opt.getIntValue ("verbose", 1);

        const char *input = opt.getValue ('I');
        if (input == 0)
                input = "test.oa";

        srand (randvalseed);
        if (randvalseed == -1) {
                randvalseed = time (NULL);
                printf ("random seed %d\n", randvalseed);
                srand (randvalseed);
        }

<<<<<<< HEAD
        {
            array_link al = exampleArray(0);
            //array_link al(3,4,0);
            //al.setconstant(0);
            arraydata_t ad = arraylink2arraydata(al);
            ad.show();
            
            array_transformation_t tt = reduceOAnauty(al, 3);
            tt.show();
              array_transformation_t tt2;
              tt2.show();
    return 0;
        }
        
        {
                setloglevel (DEBUG);

                int N = 16;
                arraydata_t ad (2, N, 2, 6);
                ad.show ();
                array_link root = ad.create_root ();

                arraylist_t lst;
                lst.push_back (root);

                arraylist_t r = extend_arraylist (lst, ad);
                printf ("extended to %d designs\n", (int)r.size ());
                exit (0);
        }
        {
                arraylist_t ll = readarrayfile (input);

                lmc_t r = LMC0checkDC (ll[0], verbose);
                // printf ( "array %d: result %d (LMC_LESS %d, LMC_MORE %d)\n", ( int ) 0, ( int ) r, LMC_LESS,
                // LMC_MORE ); exit(0);

                for (size_t i = 0; i < ll.size (); i++) {
                        lmc_t r = LMC0checkDC (ll[i], verbose >= 2);
                        printf ("array %d: result %d (LMC_LESS %d, LMC_MORE %d)\n", (int)i, (int)r, LMC_LESS,
                                LMC_MORE);

                        // randomize
                        array_link al = ll[i];

                        for (int jj = 0; jj < 30; jj++) {
                                conference_transformation_t tr (al);
                                tr.randomizecolperm ();
                                tr.randomizerowperm ();
                                tr.randomizecolflips ();

                                array_link alx = tr.apply (al);

                                if (al != alx) {
                                        lmc_t r = LMC0checkDC (alx, verbose >= 2);

                                        printf ("  randomized array %d: result %d (LMC_LESS %d, LMC_MORE %d)\n",
                                                (int)i, (int)r, LMC_LESS, LMC_MORE);
                                        if (r != LMC_LESS) {
                                                printf ("error!?\n");
                                                exit (1);
                                        }
                                } else {
                                        printf (" randomized array %d: same array\n", (int)i);
                                }
                        }
                }

                return 0;
        }
        {
                array_link al = exampleArray (r);

                array_transformation_t tt = reduceOAnauty (al);
                array_link alx = tt.apply (al);
                exit (0);
        }

        {
                bool addcol = true;

                int nx = 3;
                array_link G (nx, nx, array_link::INDEX_DEFAULT);
                G.setconstant (0);
                G.at (0, 1) = 1;
                G.at (1, 0) = 1;
                if (addcol)
                        G.at (nx - 1, nx - 1) = 5;

                // arraydata_t ad = arraylink2arraydata(G);
                arraydata_t ad (6, nx, 2, nx);

                // ad.show();
                array_transformation_t T (ad);

                T.reset ();

                std::vector< int > perm (nx);
                for (size_t i = 0; i < perm.size (); i++)
                        perm[i] = i;
                random_perm (perm);

                T.setrowperm (perm);
                T.setcolperm (perm);
                T.show ();

                G.showarray ();
                G = T.apply (G);
                G.showarray ();

                std::vector< int > colors (G.n_rows);
                for (size_t i = 0; i < colors.size (); i++)
                        colors[i] = 0;
                if (addcol)
                        colors[nx - 1] = 1;
                std::vector< int > colorsx (G.n_rows);
                colorsx = permute (colors, perm);
                // colorsx = permuteback(colors, perm);

                printfd ("colorsx.size %d\n", colorsx.size ());
                print_perm ("colorsx", colorsx);

                std::vector< int > tr = nauty::reduceNauty (G, colorsx, verbose);
                print_perm ("tr        ", tr);
                print_perm ("tr inverse", invert_permutation (tr));
                tr = invert_permutation (tr);

                myprintf ("-- output:\n");
                array_link Gx = transformGraph (G, tr, verbose);
                Gx.showarray ();

                exit (0);
        }
        if (1) {
                array_link al = exampleArray (r, 1);
                conference_t ct (al.n_rows, al.n_columns + 4, 0);
                ct.j3zero = 0;

                if (xx > 0)
                        al = al.selectFirstColumns (xx);

                if (verbose >= 1)
                        al.showarray ();

                assert (al.is_conference ());
                assert (al.min () == -1);

                int filterj2 = 1;
                int filtersymminline = 1;
                int averbose = verbose;
<<<<<<< HEAD
                std::vector< cperm > ccX = generateSingleConferenceExtensions (al, ct, -1, averbose, 1, filterj2,
=======
                std::vector< conference_column > ccX = generateSingleConferenceExtensions (al, ct, -1, averbose, 1, filterj2,
>>>>>>> eda3ae59b7a81637e44d4cf3d072fd59c47ce60a
                                                                               ct.j3zero, filtersymminline);
                showCandidates (ccX);
                printf ("\n-----------\n");

                CandidateGenerator cgenerator (array_link (), ct);
                int kz = maxz (al) + 1;
                cgenerator.verbose = verbose;
<<<<<<< HEAD
                std::vector< cperm > ee = cgenerator.generateCandidatesZero (al, kz);
=======
                std::vector< conference_column > ee = cgenerator.generateCandidatesZero (al, kz);
>>>>>>> eda3ae59b7a81637e44d4cf3d072fd59c47ce60a

                cgenerator.showCandidates (2);
                printf ("generateCandidatesZero: %d\n-------------\n", (int)ee.size ());

                exit (0);
        }
        if (0) {
                const int N = 16;
                int j1zero = 1;
                conference_t ct (N, 4, j1zero);
                ct.ctype = conference_t::DCONFERENCE;
                ct.j3zero = 1;

                if (0) {
                        arraylist_t ll = ct.createDconferenceRootArrays ();
                        printfd ("generated %d root arrays\n", ll.size ());
                        // array_link al2 = ct.create_root();
                        //        array_link al3 = ct.create_root_three();
                        array_link al = ll[0];
                }
                array_link al = exampleArray (r, 1);
                al.showarray ();
                // exit(0);

                CandidateGeneratorDouble cgenerator (array_link (), ct);
                cgenerator.verbose = 2;
                for (int i = 0; i < 2; i++) {
                        {
                                printf ("\n---------------------------------\n");
<<<<<<< HEAD
                                const std::vector< cperm > &cl = cgenerator.generateCandidates (al);
=======
                                const std::vector< conference_column > &cl = cgenerator.generateCandidates (al);
>>>>>>> eda3ae59b7a81637e44d4cf3d072fd59c47ce60a
                                printfd ("generated %d\n", cl.size ());
                                cgenerator.showCandidates (2);
                        }
                }
                exit (0);
        }
        {
                int j1zero = 0;
                const int N = r;

                conference_t ctype (N, 4, j1zero);
                ctype.ctype = conference_t::CONFERENCE_DIAGONAL;
                ctype.ctype = conference_t::CONFERENCE_NORMAL;
                ctype.itype = CONFERENCE_ISOMORPHISM;
                ctype.j3zero = 0;

                array_link al2 = ctype.create_root ();
                array_link al3 = ctype.create_root_three ();

                int ii = 2;
                int ncstart = 2;
                int ncmax = 2;
                array_link root = al2;

                if (0) {
                        int extcol = 2;
<<<<<<< HEAD
                        std::vector< cperm > ee = generateConferenceExtensions (al2, ctype, extcol, 0, 0, 1);
=======
                        std::vector< conference_column > ee = generateConferenceExtensions (al2, ctype, extcol, 0, 0, 1);
>>>>>>> eda3ae59b7a81637e44d4cf3d072fd59c47ce60a
                        printfd ("generated %d\n", ee.size ());
                }

                if (0) {
                        int extcol = 3;
<<<<<<< HEAD
                        std::vector< cperm > ee2 = generateConferenceExtensions (al3, ctype, extcol, 0, 0, 1);
=======
                        std::vector< conference_column > ee2 = generateConferenceExtensions (al3, ctype, extcol, 0, 0, 1);
>>>>>>> eda3ae59b7a81637e44d4cf3d072fd59c47ce60a

                        //    conf_candidates_t tmp = generateCandidateExtensions ( ctype, 2, ncstart, ncmax, root );
                }
                printf ("------------------------------\n");

                CandidateGenerator cgenerator (array_link (), ctype);
                cgenerator.verbose = verbose;
                // cgenerator.generators[ii].verbose=2;
                cgenerator.showCandidates (2);

                printf ("------------------------------\n");
<<<<<<< HEAD
                const std::vector< cperm > &cl = cgenerator.generateCandidatesZero (al2, ii);
=======
                const std::vector< conference_column > &cl = cgenerator.generateCandidatesZero (al2, ii);
>>>>>>> eda3ae59b7a81637e44d4cf3d072fd59c47ce60a
                cgenerator.showCandidates (2);
                printfd (" cache: generated %d\n", cl.size ());

                exit (0);
=======
>>>>>>> pieter/dev


		array_link al = exampleArray(36, verbose);
		myassert(al.is_conference(2), "check on double conference design type");

		for (int i = 0; i < 100; i++) {
			myprintf("iteration %d\n", i);
			myassert(testLMC0checkDC(al, verbose >= 2), "testLMC0checkDC");
		}
		exit(0);

		try {
			array_link al = exampleArray(r);
			al.show();
			al.showarray();

			std::vector<int> sizes = array2modelmatrix_sizes(al);
			display_vector(sizes); myprintf("\n");
			MatrixFloat modelmatrix = array2modelmatrix(al, "i", 1);
			array_link modelmatrixx = modelmatrix;
			modelmatrixx.show();
			modelmatrixx.showarray();

			modelmatrix = array2modelmatrix(al, "main", 1);
			modelmatrixx = modelmatrix;
			modelmatrixx.show();
			modelmatrixx.showarray();

			exit(0);

		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
			throw;
		}

        {
                array_link al = exampleArray (r);

                array_transformation_t tt = reduceOAnauty (al);
                array_link alx = tt.apply (al);
                exit (0);
        }


<<<<<<< HEAD
                arraylist_t ll = readarrayfile ("x.oa");
                array_link al = ll[0];

                if (1) {
                        printf ("test conf foldover\n");
                        for (int i = 0; i < (int)ll.size (); i++) {
                                isConferenceFoldover (ll[i]);
                        }
                        exit (0);
                }
<<<<<<< HEAD
                // int ctype=2;
=======
>>>>>>> eda3ae59b7a81637e44d4cf3d072fd59c47ce60a
                conference_t ctype (al.n_rows, al.n_rows, 1);
                ctype.itype = CONFERENCE_RESTRICTED_ISOMORPHISM;
                ctype.ctype = conference_t::DCONFERENCE;

                CandidateGeneratorDouble cgenerator (array_link (), ctype);
                cgenerator.verbose = verbose;

                for (int i = 0; i < (int)ll.size (); i++) {
<<<<<<< HEAD
                        std::vector< cperm > cc = cgenerator.generateCandidates (ll[i]);
=======
                        std::vector< conference_column > cc = cgenerator.generateCandidates (ll[i]);
>>>>>>> eda3ae59b7a81637e44d4cf3d072fd59c47ce60a
                        printfd ("generated %d\n", cc.size ());
                }
                exit (0);
        }
=======
>>>>>>> pieter/dev

        return 0;
}

// kate: indent-mode cstyle; indent-width 5; replace-tabs on;
