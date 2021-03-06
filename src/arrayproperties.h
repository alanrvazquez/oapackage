/*! \file arrayproperties.h
 \brief Contains functions to calculate properties of arrays

 Author: Pieter Eendebak <pieter.eendebak@gmail.com>
 Copyright: See LICENSE.txt file that comes with this distribution
*/

#pragma once

#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/SVD>

#include "arraytools.h"
#include "oaoptions.h"
#include "tools.h"

#define stringify(name) #name

/// Calculate D-efficiency and VIF-efficiency and E-efficiency values using SVD
void DAEefficiencyWithSVD (const Eigen::MatrixXd &secondorder_interaction_matrix, double &Deff, double &vif, double &Eeff, int &rank, int verbose);

/** Calculate the rank of the second order interaction matrix of an orthogonal array
 *
 * The model is the intercept, main effects and interaction effects
 * The rank, D-efficiency, VIF-efficiency and E-efficiency are appended to the second argument
 *
 * The vector ret is filled with the rank, Defficiency, VIF efficiency and Eefficiency
 */
int array2rank_Deff_Beff (const array_link &al, std::vector< double > *ret = 0, int verbose = 0);

/// Calculate D-efficiency for a 2-level array using symmetric eigenvalue decomposition
double Defficiency (const array_link &al, int verbose = 0);

std::vector< double > Defficiencies (const array_link &al, const arraydata_t &arrayclass, int verbose = 0,
                                     int addDs0 = 0);

/// Calculate VIF-efficiency of matrix
double VIFefficiency (const array_link &orthogonal_array, int verbose = 0);

/// Calculate A-efficiency of matrix
double Aefficiency (const array_link &orthogonal_array, int verbose = 0);

/// Calculate E-efficiency of matrix (1 over the VIF-efficiency)
double Eefficiency (const array_link &orthogonal_array, int verbose = 0);

/// calculate various A-efficiencies
std::vector< double > Aefficiencies (const array_link &orthogonal_array, int verbose = 0);

<<<<<<< HEAD
#ifdef FULLPACKAGE
/// Return the D-efficiencies for the projection designs
std::vector< double > projDeff (const array_link &al, int kp, int verbose);
<<<<<<< HEAD

/// Return the projection estimation capacity sequence of a design
std::vector< double > PECsequence (const array_link &al, int verbose = 0);
=======
=======
/** Calculate D-efficiencies for all projection designs
*
* \param al Design to calculate D-efficiencies for
* \param number_of_factors Number of factors into which to project
* \param verbose Verbosity level
* \returns Vector with calculated D-efficiencies
*/
std::vector< double > projDeff (const array_link &al, int number_of_factors, int verbose = 0);
>>>>>>> pieter/dev

/** Calculate the projection estimation capacity sequence for a design
*
* The PEC of a design is the fraction of estimable second-order models in x factors.
* See "Ranking Non-regular Designs", J.L. Loeppky
*
*/std::vector< double > PECsequence (const array_link &array, int verbose = 0);

/**Calculate the projection information capacity sequence for a design.
*
* The PIC of a design is the average D-efficiency of estimable second-order models in x factors.
*
*/
std::vector< double > PICsequence(const array_link &array, int verbose = 0);
<<<<<<< HEAD
>>>>>>> eda3ae59b7a81637e44d4cf3d072fd59c47ce60a
#endif
=======
>>>>>>> pieter/dev

/** Return the distance distribution of a design
 *
 * The distance distribution is described in "Generalized minimum aberration for asymmetrical fractional factorial designs", Wu and Xu, 2001
 */
std::vector< double > distance_distribution (const array_link &array);

/// Calculate J-characteristics of matrix (the values are signed)
std::vector< int > Jcharacteristics (const array_link &al, int jj = 4, int verbose = 0);

/** @brief Calculate GWLP (generalized wordlength pattern)
 *
 * The method used for calculation is from Xu and Wu (2001), "Generalized minimum aberration for asymmetrical
 * fractional factorial desings"
<<<<<<< HEAD
 *  The non-symmetric arrays see "Algorithmic Construction of Efficient Fractional Factorial Designs With Large Run
=======
 * For non-symmetric arrays see "Algorithmic Construction of Efficient Fractional Factorial Designs With Large Run
>>>>>>> eda3ae59b7a81637e44d4cf3d072fd59c47ce60a
 * Sizes", Xu
 *
 * \param array Array to calculate the GWLP value for
 * \param verbose Verbosity level
 * \param truncate If True then round values near zero to solve double precision errors
 */
<<<<<<< HEAD
std::vector< double > GWLP (const array_link &al, int verbose = 0, int truncate = 1);
=======
std::vector< double > GWLP (const array_link &array, int verbose = 0, int truncate = 1);
>>>>>>> eda3ae59b7a81637e44d4cf3d072fd59c47ce60a

/** @brief Calculate GWLP (generalized wordlength pattern) for mixed-level arrays
*
*  The method used for calculation is from Xu and Wu (2001), "Generalized minimum aberration for asymmetrical
* fractional factorial desings"
*  The non-symmetric arrays see "Algorithmic Construction of Efficient Fractional Factorial Designs With Large Run
* Sizes", Xu
*
* \param al Array to calculate the GWLP value for
* \param verbose Verbosity level
* \param truncate If True then round values near zero to solve double precision errors
*
*/
std::vector< double > GWLPmixed (const array_link &al, int verbose = 0, int truncate = 1);

// SWIG has some issues with typedefs, so we use a define
#define GWLPvalue mvalue_t< double >

typedef mvalue_t< double > DOFvalue;

/// calculate delete-one-factor GWLP (generalized wordlength pattern) projections
std::vector< GWLPvalue > projectionGWLPs (const array_link &al);

std::vector< GWLPvalue > sortGWLP (std::vector< GWLPvalue >);

/// calculate delete-one-factor GWLP (generalized wordlength pattern) projection values
<<<<<<< HEAD
std::vector< double > projectionGWLPvalues (const array_link &al);
=======
std::vector< double > projectionGWLPdoublevalues (const array_link &al);
>>>>>>> eda3ae59b7a81637e44d4cf3d072fd59c47ce60a

/** calculate centered L2-discrepancy of a design
 *
 * The method is from "A connection between uniformity and aberration in regular fractions of two-level factorials",
 * Fang and Mukerjee, 2000
 */
double CL2discrepancy (const array_link &al);

/** Calculate second order interaction model for 2-level array
*
* \param array Array to calculate second order interaction model from
* \returns Array interaction effects
*/
<<<<<<< HEAD
array_link array2secondorder (const array_link &al);
=======
array_link array2secondorder (const array_link &array);
>>>>>>> eda3ae59b7a81637e44d4cf3d072fd59c47ce60a

/** calculate second order interaction model for 2-level array
 *
 * \param array Array to calculate second order interaction model from
 * \returns Array with intercept, main effects and interaction effects
 */
<<<<<<< HEAD
array_link array2xf (const array_link &al);
=======
array_link array2xf (const array_link &array);
>>>>>>> eda3ae59b7a81637e44d4cf3d072fd59c47ce60a

/**
 *
 * \param conference_design Conference design
 * \param mode Can be 'm' for main effects, 'i' for interaction effects or 'q' for quadratic effects
 * \param verbose Verbosity level
 */
array_link conference_design2modelmatrix(const array_link & conference_design, const char*mode, int verbose);

/** Convert orthogonal array or conference design to model matrix
 *
 * Intercept, main effects, interaction effects, quadratics
 * The order in the interaction effects is (c1, c2)=(0,0), (1,0), (2,0), (2,1), ... with c2<c1
 *
 * \param array Orthogonal array or conference design
 * \param mode Can be 'm' for main effects, 'i' for interaction effects or 'q' for quadratic effects
 * \param verbose Verbosity level
 */
Eigen::MatrixXd array2modelmatrix(const array_link &array, const char *mode, int verbose = 0);


std::vector<int> array2modelmatrix_sizes(const array_link &array);

/** calculate second order interaction model for 2-level array
*
* \param array Array to calculate second order interaction model from
* \returns Array with intercept, main effects and interaction effects
*/
<<<<<<< HEAD
Eigen::MatrixXd array2xfeigen (const array_link &al);

/// return rank of an array based on FullPivHouseholderQR
int arrayrankFullPivQR (const array_link &al, double threshold = -1);

/// return rank of an array based on ColPivHouseholderQR
int arrayrankColPivQR (const array_link &al, double threshold = -1);

/// return rank of an array based on arrayrankFullPivLU
=======
Eigen::MatrixXd array2xfeigen (const array_link &array);

/// return rank of an array based on Eigen::FullPivHouseholderQR
int arrayrankFullPivQR (const array_link &al, double threshold = -1);

/// return rank of an array based on Eigen::ColPivHouseholderQR
int arrayrankColPivQR (const array_link &al, double threshold = -1);

/// return rank of an array based on Eigen::FullPivLU
>>>>>>> eda3ae59b7a81637e44d4cf3d072fd59c47ce60a
int arrayrankFullPivLU (const array_link &al, double threshold = -1);

/// return rank of an array based on Eigen::JacobiSVD
int arrayrankSVD (const array_link &al, double threshold = -1);

/// calculate the rank of an array
int arrayrank (const array_link &array);

/// Return rank of an array. Information about the different methods for rank calculation is printed to stdout
int arrayrankInfo (const Eigen::MatrixXd &, int verbose = 1);

/// Return rank of an array. Information about the different methods for rank calculation is printed to stdout
int arrayrankInfo (const array_link &array, int verbose = 1);

/// convert array_link to Eigen matrix
Eigen::MatrixXd arraylink2eigen (const array_link &array);

/** Structure to efficiently calculate the rank of the second order interaction matrix of many arrays
 *
 * The efficiency is obtained if the arrays share a common subarray. The theory is described in "Efficient rank calculation for matrices with a common submatrix", Eendebak, 2016
 *
 **/
class rankStructure {
      public:
        typedef Eigen::FullPivHouseholderQR< Eigen::MatrixXd > EigenDecomp;

      public:
        array_link alsub;
        int r;
        /// verbosity level
        int verbose;
        /// number of columns of subarray in cache
        int ks;
        /// number of columns to subtract from array when updating cache
        int nsub;
        /// used for debugging
        int id;

      private:
        /// decomposition of subarray
        EigenDecomp decomp;
        Eigen::MatrixXd Qi;

        /// internal structure
        long ncalc, nupdate;

      public:
        /// constructor
        rankStructure (const array_link &al, int nsub = 3, int verbose = 0) {
                this->verbose = verbose;
                ks = 0;
                this->nsub = nsub;
                this->id = -1;
                ncalc = 0;
                nupdate = 0;
                updateStructure (al);
        }
        /// constructor
        rankStructure (int nsub = 3, int id = -1) {
                this->verbose = 0;
                ks = 0;
                this->nsub = nsub;
                this->id = id;
                ncalc = 0;
                nupdate = 0;

                array_link al = exampleArray (1);
                updateStructure (al);
        }

		/// print information about the rank structure
		void info() const;

        /// update the structure cache with a new array
		void updateStructure(const array_link &al);

        /// calculate the rank of an array directly, uses special threshold
		int rankdirect(const Eigen::MatrixXd &array) const;

        /// calculate the rank of the second order interaction matrix of an array directly
<<<<<<< HEAD
        int rankxfdirect (const array_link &al) const {
<<<<<<< HEAD
                Eigen::MatrixXd mymatrix = arraylink2eigen (array2xf (al)); // array2xf;
=======
                Eigen::MatrixXd mymatrix = arraylink2eigen (array2xf (al)); 
>>>>>>> eda3ae59b7a81637e44d4cf3d072fd59c47ce60a
                return rankdirect (mymatrix);
        }
=======
		int rankxfdirect(const array_link &array) const;
>>>>>>> pieter/dev

        /// calculate the rank of the second order interaction matrix of an array using the cache system
        int rankxf (const array_link &array);
};

/// Return the condition number of a matrix
double conditionNumber (const array_link &matrix);

#ifdef FULLPACKAGE

#include "pareto.h"

enum paretomethod_t { PARETOFUNCTION_DEFAULT, PARETOFUNCTION_J5 };

/** Calculate the Pareto optimal arrays from a list of array files

    Pareto optimality is calculated according to (rank; A3,A4; F4)
*/
void calculateParetoEvenOdd (const std::vector< std::string > infiles, const char *outfile, int verbose = 1,
                             arrayfilemode_t afmode = ABINARY, int nrows = -1, int ncols = -1,
                             paretomethod_t paretomethod = PARETOFUNCTION_DEFAULT);

// Calculate the Pareto optimal desings from a list of arrays (rank; A3,A4; F4)
Pareto< mvalue_t< long >, long > parsePareto (const arraylist_t &arraylist, int verbose,
                                              paretomethod_t paretomethod = PARETOFUNCTION_DEFAULT);

/** calculate A3 and A4 value for array
 *
 * \param al Array for which to calculate A3 and A4
 * \returns Object with A3 and A4
 */
mvalue_t< long > A3A4 (const array_link &al);

/// calculate F4 value for 2-level array
inline mvalue_t< long > F4 (const array_link &al, int verbose = 1) {
        jstruct_t js (al, 4);
        std::vector< int > FF = js.calculateF ();
        if (verbose >= 3) {
                myprintf ("  parseArrayPareto: F (high to low): ");
                display_vector (FF);
                myprintf ("\n");
        }

        mvalue_t< long > v (FF, mvalue_t< long >::LOW);
        return v;
}

template < class IndexType >
/** Add array to list of Pareto optimal arrays
 *
 * The values to be optimized are:
 *
 * 1) Rank (higher is better)
 * 2) A3, A4 (lower is better)
 * 3) F4 (lower is better, sum of elements is constant)
 *
 * Valid for 2-level arrays of strength at least 3
 *
 * */
typename Pareto< mvalue_t< long >, IndexType >::pValue calculateArrayParetoRankFA (const array_link &al,
                                                                                          int verbose) {
        int N = al.n_rows;
        int model_rank = arrayrankFullPivLU (array2secondorder (al), 1e-12) + 1 +
                         al.n_columns; // valid for 2-level arrays of strength at least 3
        mvalue_t< long > a3a4_values = A3A4 (al);
        mvalue_t< long > f4 = F4 (al);

        // add the 3 values to the combined value
        typename Pareto< mvalue_t< long >, IndexType >::pValue p;
        p.push_back (model_rank);
        p.push_back (a3a4_values);
        p.push_back (f4);

        if (verbose >= 2) {
                if (verbose >= 3) {
                        std::vector< double > gwlp = al.GWLP ();
<<<<<<< HEAD
                        myprintf ("parseArrayPareto: A4 (scaled) %ld, %f\n", a3a4_values.v[1], gwlp[4]);
=======
                        myprintf ("parseArrayPareto: A4 (scaled) %ld, %f\n", a3a4_values.raw_values()[1], gwlp[4]);
>>>>>>> eda3ae59b7a81637e44d4cf3d072fd59c47ce60a
                }

                myprintf ("  parseArrayPareto: rank %d, verbose %d\n", al.rank (), verbose);
        }

        return p;
}

/// add Jmax criterium to Pareto set
template < class IndexType >
void addJmax (const array_link &al, typename Pareto< mvalue_t< long >, IndexType >::pValue &p, int verbose = 1) {
        std::vector< int > j5 = al.Jcharacteristics (5);
        int j5max = vectormax (j5, 0);

        int v1 = (j5max == al.n_rows);
        int v2 = 1 - v1;

        if (verbose >= 3) {
                printf ("calculateArrayParetoJ5: j5max %d: %d %d\n", j5max, v1, v2);
        }

        p.push_back (v1);
        p.push_back (v2);
}

template < class IndexType >
typename Pareto< mvalue_t< long >, IndexType >::pValue calculateArrayParetoJ5 (const array_link &al, int verbose) {
        typename Pareto< mvalue_t< long >, IndexType >::pValue p =
            calculateArrayParetoRankFA< IndexType > (al, verbose);
        addJmax< IndexType > (al, p, verbose);

        return p;
}

template < class IndexType >
/** Add array to list of Pareto optimal arrays
 *
 * The values to be optimized are:
 *
 * 1) Rank (higher is better)
 * 2) A3, A4 (lower is better)
 * 3) F4 (lower is better, sum of elements is constant)
 *
 * */
inline void parseArrayPareto (const array_link &al, IndexType i, Pareto< mvalue_t< long >, IndexType > &pset,
                              int verbose) {
        typename Pareto< mvalue_t< long >, IndexType >::pValue p =
            calculateArrayParetoRankFA< IndexType > (al, verbose);

        // add the new tuple to the Pareto set
        pset.addvalue (p, i);
}

#endif // FULLPACKAGE

/// convert C value to D-efficiency value
inline double Cvalue2Dvalue (double Cvalue, int number_of_columns) {
        double ma = 1 + number_of_columns + number_of_columns * (number_of_columns - 1) / 2;
        double Defficiency = pow (Cvalue, 1. / ma);

        return Defficiency;
}

/// convert D-efficiency value to C value
inline double Dvalue2Cvalue (double Defficiency, int number_of_columns) {
        int ma = 1 + number_of_columns + number_of_columns * (number_of_columns - 1) / 2;
        double Cvalue = pow (Defficiency, ma);

        return Cvalue;
}

<<<<<<< HEAD
/// Return index of an array
inline int get_oaindex (const array_t *s, const colindex_t strength, const colindex_t N) {
        int oaindex = N;
        for (colindex_t z = 0; z < strength; z++) {
                oaindex /= s[z];
        }
=======
>>>>>>> eda3ae59b7a81637e44d4cf3d072fd59c47ce60a

        return oaindex;
}

