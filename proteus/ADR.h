#ifndef ADR_H
#define ADR_H
#include <cmath>
#include <iostream>
#include "CompKernel.h"
#include "ModelFactory.h"
#include "xtensor-python/pyarray.hpp"

namespace py = pybind11;

namespace proteus
{
    class cppADR_base
    {
        public:
        virtual ~cppADR_base(){}
        virtual void calculateResidual(//element
                                       xt::pyarray<double>& mesh_trial_ref,
                                       xt::pyarray<double>& mesh_grad_trial_ref,
                                       xt::pyarray<double>& mesh_dof,
                                       xt::pyarray<int>& mesh_l2g,
                                       xt::pyarray<double>& dV_ref,
                                       xt::pyarray<double>& u_trial_ref,
                                       xt::pyarray<double>& u_grad_trial_ref,
                                       xt::pyarray<double>& u_test_ref,
                                       xt::pyarray<double>& u_grad_test_ref,
                                       xt::pyarray<double>& elementDiameter,
                                       xt::pyarray<double>& cfl,
                                       double Ct_sge,
                                       double sc_uref,
                                       double sc_alpha,
                                       double useMetrics,
                                       //element boundary
                                       xt::pyarray<double>& mesh_trial_trace_ref,
                                       xt::pyarray<double>& mesh_grad_trial_trace_ref,
                                       xt::pyarray<double>& dS_ref,
                                       xt::pyarray<double>& u_trial_trace_ref,
                                       xt::pyarray<double>& u_grad_trial_trace_ref,
                                       xt::pyarray<double>& u_test_trace_ref,
                                       xt::pyarray<double>& u_grad_test_trace_ref,
                                       xt::pyarray<double>& normal_ref,
                                       xt::pyarray<double>& boundaryJac_ref,
                                       //physics
                                       int nElements_global,
                                       xt::pyarray<int>& u_l2g,
                                       xt::pyarray<double>& u_dof,
                                       xt::pyarray<int>& sd_rptr,
                                       xt::pyarray<int>& sd_colind,
                                       xt::pyarray<double>& q_a,
                                       xt::pyarray<double>& q_v,
                                       xt::pyarray<double>& q_r,
                                       int lag_shockCapturing,
                                       double shockCapturingDiffusion,
                                       xt::pyarray<double>& q_numDiff_u,
                                       xt::pyarray<double>& q_numDiff_u_last,
                                       int offset_u,
                                       int stride_u,
                                       xt::pyarray<double>& globalResidual,
                                       int nExteriorElementBoundaries_global,
                                       xt::pyarray<int>& exteriorElementBoundariesArray,
                                       xt::pyarray<int>& elementBoundaryElementsArray,
                                       xt::pyarray<int>& elementBoundaryLocalElementBoundariesArray,
                                       xt::pyarray<double>& ebqe_a,
                                       xt::pyarray<double>& ebqe_v,
                                       xt::pyarray<int>& isDOFBoundary_u,
                                       xt::pyarray<double>& ebqe_bc_u_ext,
                                       xt::pyarray<int>& isDiffusiveFluxBoundary_u,
                                       xt::pyarray<int>& isAdvectiveFluxBoundary_u,
                                       xt::pyarray<double>& ebqe_bc_flux_u_ext,
                                       xt::pyarray<double>& ebqe_bc_advectiveFlux_u_ext,
                                       xt::pyarray<double>& ebqe_penalty_ext,
                                       const double eb_adjoint_sigma
                                      ) = 0;
        virtual void calculateJacobian(//element
                                       xt::pyarray<double>& mesh_trial_ref,
                                       xt::pyarray<double>& mesh_grad_trial_ref,
                                       xt::pyarray<double>& mesh_dof,
                                       xt::pyarray<int>& mesh_l2g,
                                       xt::pyarray<double>& dV_ref,
                                       xt::pyarray<double>& u_trial_ref,
                                       xt::pyarray<double>& u_grad_trial_ref,
                                       xt::pyarray<double>& u_test_ref,
                                       xt::pyarray<double>& u_grad_test_ref,
                                       xt::pyarray<double>& elementDiameter,
                                       xt::pyarray<double>& cfl,
                                       double Ct_sge,
                                       double sc_uref,
                                       double sc_alpha,
                                       double useMetrics,
                                       //element boundary
                                       xt::pyarray<double>& mesh_trial_trace_ref,
                                       xt::pyarray<double>& mesh_grad_trial_trace_ref,
                                       xt::pyarray<double>& dS_ref,
                                       xt::pyarray<double>& u_trial_trace_ref,
                                       xt::pyarray<double>& u_grad_trial_trace_ref,
                                       xt::pyarray<double>& u_test_trace_ref,
                                       xt::pyarray<double>& u_grad_test_trace_ref,
                                       xt::pyarray<double>& normal_ref,
                                       xt::pyarray<double>& boundaryJac_ref,
                                       //physics
                                       int nElements_global,
                                       xt::pyarray<int>& u_l2g,
                                       xt::pyarray<double>& u_dof,
                                       xt::pyarray<int>& sd_rowptr,
                                       xt::pyarray<int>& sd_colind,
                                       xt::pyarray<double>& q_a,
                                       xt::pyarray<double>& q_v,
                                       xt::pyarray<double>& q_r,
                                       int lag_shockCapturing,
                                       double shockCapturingDiffusion,
                                       xt::pyarray<double>& q_numDiff_u,
                                       xt::pyarray<double>& q_numDiff_u_last,
                                       xt::pyarray<int>& csrRowIndeces_u_u,xt::pyarray<int>& csrColumnOffsets_u_u,
                                       xt::pyarray<double>& globalJacobian,
                                       int nExteriorElementBoundaries_global,
                                       xt::pyarray<int>& exteriorElementBoundariesArray,
                                       xt::pyarray<int>& elementBoundaryElementsArray,
                                       xt::pyarray<int>& elementBoundaryLocalElementBoundariesArray,
                                       xt::pyarray<double>& ebqe_a,
                                       xt::pyarray<double>& ebqe_v,
                                       xt::pyarray<int>& isDOFBoundary_u,
                                       xt::pyarray<double>& ebqe_bc_u_ext,
                                       xt::pyarray<int>& isDiffusiveFluxBoundary_u,
                                       xt::pyarray<int>& isAdvectiveFluxBoundary_u,
                                       xt::pyarray<double>& ebqe_bc_flux_u_ext,
                                       xt::pyarray<double>& ebqe_bc_advectiveFlux_u_ext,
                                       xt::pyarray<int>& csrColumnOffsets_eb_u_u,
                                       xt::pyarray<double>& ebqe_penalty_ext,
                                       const double eb_adjoint_sigma
                                      ) = 0;
    };

    template<class CompKernelType,
             int nSpace,
             int nQuadraturePoints_element,
             int nDOF_mesh_trial_element,
             int nDOF_trial_element,
             int nDOF_test_element,
             int nQuadraturePoints_elementBoundary
            >
    class cppADR: public cppADR_base
    {
        public:
        const int nDOF_test_X_trial_element;
        CompKernelType ck;
        cppADR(): nDOF_test_X_trial_element(nDOF_test_element*nDOF_trial_element), ck()
        {}
        /* inline
        void evaluateCoefficients()
        {
        }
        */

        inline
        void exteriorNumericalDiffusiveFlux(int* rowptr,
                                            int* colind,
                                            const int& isDOFBoundary,
                                            const int& isDiffusiveFluxBoundary,
                                            const double n[nSpace],
                                            double* bc_a,
                                            const double& bc_u,
                                            const double& bc_flux,
                                            double* a,
                                            const double grad_potential[nSpace],
                                            const double& u,
                                            const double& penalty,
                                            double& flux)
        {
            double diffusiveVelocityComponent_I;
            double penaltyFlux;
            double max_a;
            if (isDiffusiveFluxBoundary == 1)
            {
                flux = bc_flux;
            }
            else if (isDOFBoundary == 1)
            {
                flux = 0.0;
                max_a = 0.0;
                for (int I = 0; I < nSpace; I++)
                {
                    diffusiveVelocityComponent_I = 0.0;
                    for (int m = rowptr[I]; m < rowptr[I+1]; m++)
                    {
                        diffusiveVelocityComponent_I -= a[m] * grad_potential[colind[m]];
                        max_a = fmax(max_a, a[m]);
                    }
                    flux += diffusiveVelocityComponent_I * n[I];
                }
                penaltyFlux = max_a * penalty * (u - bc_u);
                flux += penaltyFlux;
            }
            else
            {
                std::cerr << "warning, diffusion term with no boundary condition set, setting diffusive flux to 0.0" << std::endl;
                flux = 0.0;
            }
        }

        inline
        double ExteriorNumericalDiffusiveFluxJacobian(int* rowptr,
                                                      int* colind,
                                                      const int& isDOFBoundary,
                                                      const int& isDiffusiveFluxBoundary,
                                                      const double n[nSpace],
                                                      double* a,
                                                      const double& v,
                                                      const double grad_v[nSpace],
                                                      const double& penalty)
        {
            double dvel_I;
            double tmp = 0.0;
            double max_a = 0.0;
            if ((isDiffusiveFluxBoundary == 0) && (isDOFBoundary == 1))
            {
                for (int I = 0; I < nSpace; I++)
                {
                    dvel_I = 0.0;
                    for (int m = rowptr[I]; m < rowptr[I + 1]; m++)
                    {
                        dvel_I -= a[m] * grad_v[colind[m]];
                        max_a = fmax(max_a, a[m]);
                    }
                    tmp += dvel_I * n[I];
                }
                tmp += max_a * penalty * v;
            }
            return tmp;
        }

        inline
        void calculateSubgridError_tau(const double& elementDiameter,
                                       const double& dmt,
                                       const double dH[nSpace],
                                       double& cfl,
                                       double& tau)
        {
            double h;
            double nrm_v;
            double oneByAbsdt;
            h = elementDiameter;
            nrm_v = 0.0;
            for(int I = 0; I < nSpace; I++)
                nrm_v += dH[I] * dH[I];
            nrm_v = sqrt(nrm_v);
            cfl = nrm_v / h;
            oneByAbsdt = fabs(dmt);
            tau = 1.0 / (2.0 * nrm_v / h + oneByAbsdt + 1.0e-8);
        }

        inline
        void calculateSubgridError_tau(const double& Ct_sge,
                                       const double G[nSpace*nSpace],
                                       const double& A0,
                                       const double Ai[nSpace],
                                       double& tau_v,
                                       double& cfl)
        {
            double v_d_Gv = 0.0;
            for (int I = 0; I < nSpace; I++)
                for (int J = 0; J < nSpace; J++)
                    v_d_Gv += Ai[I] * G[I * nSpace + J] * Ai[J];
            tau_v = 1.0 / sqrt(Ct_sge * A0 * A0 + v_d_Gv + 1.0e-8);
        }

        inline
        void calculateNumericalDiffusion(const double& shockCapturingDiffusion,
                                         const double& elementDiameter,
                                         const double& strong_residual,
                                         const double grad_u[nSpace],
                                         double& numDiff)
        {
            double h;
            double num;
            double den;
            double n_grad_u;
            h = elementDiameter;
            n_grad_u = 0.0;
            for (int I = 0; I < nSpace; I++)
                n_grad_u += grad_u[I] * grad_u[I];
            num = shockCapturingDiffusion * 0.5 * h * fabs(strong_residual);
            den = sqrt(n_grad_u) + 1.0e-8;
            numDiff = num / den;
        }

        inline
        void exteriorNumericalAdvectiveFlux(const int& isDOFBoundary_u,
                                            const int& isFluxBoundary_u,
                                            const double n[nSpace],
                                            const double& bc_u,
                                            const double& bc_flux_u,
                                            const double& u,
                                            const double velocity[nSpace],
                                            double& flux)
        {

            double flow = 0.0;
            for (int I = 0; I < nSpace; I++)
                flow += n[I] * velocity[I];
            if (isDOFBoundary_u == 1)
            {
                if (flow >= 0.0)
                {
                    flux = u * flow;
                    //flux = flow;
                }
                else
                {
                    flux = bc_u * flow;
                    //flux = flow;
                }
            }
            else if (isFluxBoundary_u == 1)
            {
                flux = bc_flux_u;
            }
            else
            {
                if (flow >= 0.0)
                {
                    flux = u * flow;
                }
                else
                {
                    flux = 0.0;
                }

            }
            //flux = flow;
        }

        inline
        void exteriorNumericalAdvectiveFluxDerivative(const int& isDOFBoundary_u,
                                                      const int& isFluxBoundary_u,
                                                      const double n[nSpace],
                                                      const double velocity[nSpace],
                                                      double& dflux)
        {
            double flow = 0.0;
            for (int I = 0; I < nSpace; I++)
            {
                flow += n[I] * velocity[I];
            }
            //double flow=n[0]*velocity[0]+n[1]*velocity[1]+n[2]*velocity[2];
            dflux = 0.0;//default to no flux
            if (isDOFBoundary_u == 1)
            {
                if (flow >= 0.0)
                {
                    dflux = flow;
                }
                else
                {
                    dflux = 0.0;
                }
            }
            else if (isFluxBoundary_u == 1)
            {
                dflux = 0.0;
            }
            else
            {
                if (flow >= 0.0)
                {
                    dflux = flow;
                }
            }
        }

        inline void calculateElementResidual(//element
                                             xt::pyarray<double>& mesh_trial_ref,
                                             xt::pyarray<double>& mesh_grad_trial_ref,
                                             xt::pyarray<double>& mesh_dof,
                                             xt::pyarray<int>& mesh_l2g,
                                             xt::pyarray<double>& dV_ref,
                                             xt::pyarray<double>& u_trial_ref,
                                             xt::pyarray<double>& u_grad_trial_ref,
                                             xt::pyarray<double>& u_test_ref,
                                             xt::pyarray<double>& u_grad_test_ref,
                                             xt::pyarray<double>& elementDiameter,
                                             xt::pyarray<double>& cfl,
                                             double Ct_sge,
                                             double sc_uref,
                                             double sc_alpha,
                                             double useMetrics,
                                             //element boundary
                                             xt::pyarray<double>& mesh_trial_trace_ref,
                                             xt::pyarray<double>& mesh_grad_trial_trace_ref,
                                             xt::pyarray<double>& dS_ref,
                                             xt::pyarray<double>& u_trial_trace_ref,
                                             xt::pyarray<double>& u_grad_trial_trace_ref,
                                             xt::pyarray<double>& u_test_trace_ref,
                                             xt::pyarray<double>& u_grad_test_trace_ref,
                                             xt::pyarray<double>& normal_ref,
                                             xt::pyarray<double>& boundaryJac_ref,
                                             //physics
                                             int nElements_global,
                                             xt::pyarray<int>& u_l2g,
                                             xt::pyarray<double>& u_dof,
                                             xt::pyarray<int>& sd_rowptr,
                                             xt::pyarray<int>& sd_colind,
                                             xt::pyarray<double>& q_a,
                                             xt::pyarray<double>& q_v,
                                             xt::pyarray<double>& q_r,
                                             int lag_shockCapturingDiffusion,
                                             double shockCapturingDiffusion,
                                             xt::pyarray<double>& q_numDiff_u,
                                             xt::pyarray<double>& q_numDiff_u_last,
                                             int offset_u,
                                             int stride_u,
                                             xt::pyarray<double>& elementResidual_u,
                                             int nExteriorElementBoundaries_global,
                                             xt::pyarray<int>& exteriorElementBoundariesArray,
                                             xt::pyarray<int>& elementBoundaryElementsArray,
                                             xt::pyarray<int>& elementBoundaryLocalElementBoundariesArray,
                                             xt::pyarray<double>& element_u,
                                             int eN)
                {
                    for (int i = 0; i < nDOF_test_element; i++)
                    {
                        elementResidual_u.data()[i] = 0.0;
                    }
                    //loop over quadrature points and compute integrands
                    for (int k = 0; k < nQuadraturePoints_element; k++)
                    {
                        //compute indeces and declare local storage
                        int eN_k = eN * nQuadraturePoints_element + k;
                        double u = 0.0;
                        double grad_u[nSpace];
                        double m = 0.0;
                        double dm=0.0;
                        double f[nSpace];
                        double df[nSpace];
                        double m_t = 0.0;
                        double dm_t = 0.0;
                        double pdeResidual_u = 0.0;
                        double Lstar_u[nDOF_test_element];
                        double subgridError_u = 0.0;
                        double tau = 0.0;
                        double tau0 = 0.0;
                        double tau1 = 0.0;
                        double numDiff0 = 0.0;
                        double numDiff1 = 0.0;
                        double *a = NULL;
                        double r = 0.0;
                        double jac[nSpace*nSpace];
                        double jacDet;
                        double jacInv[nSpace*nSpace];
                        double u_grad_trial[nDOF_trial_element * nSpace];
                        double u_test_dV[nDOF_trial_element];
                        double u_grad_test_dV[nDOF_test_element * nSpace];
                        double dV;
                        double x;
                        double y;
                        double z;
                        double G[nSpace * nSpace];
                        double G_dd_G;
                        double tr_G;
                        //
                        //compute solution and gradients at quadrature points
                        //
                        ck.calculateMapping_element(eN,
                                                    k,
                                                    mesh_dof.data(),
                                                    mesh_l2g.data(),
                                                    mesh_trial_ref.data(),
                                                    mesh_grad_trial_ref.data(),
                                                    jac,
                                                    jacDet,
                                                    jacInv,
                                                    x,
                                                    y,
                                                    z);
                        //get the physical integration weight
                        dV = fabs(jacDet) * dV_ref[k];
                        //get the metric tensor and friends
                        ck.calculateG(jacInv, G, G_dd_G, tr_G);
                        //get the trial function gradients
                        ck.gradTrialFromRef(&u_grad_trial_ref[k * nDOF_trial_element * nSpace], jacInv, u_grad_trial);
                        //get the solution
                        ck.valFromElementDOF(element_u.data(), &u_trial_ref[k * nDOF_trial_element], u);
                        //get the solution gradients
                        ck.gradFromElementDOF(element_u.data(), u_grad_trial, grad_u);
                        //precalculate test function products with integration weights
                        for (int j = 0; j < nDOF_trial_element; j++)
                        {
                            u_test_dV[j] = u_test_ref[k * nDOF_trial_element + j] * dV;
                            for (int I = 0; I < nSpace; I++)
                            {
                                u_grad_test_dV[j * nSpace + I] = u_grad_trial[j * nSpace + I] *dV; //cek warning won't work for Petrov-Galerkin
                            }
                        }

                        //
                        //calculate pde coefficients at quadrature points
                        //
                        //evaluateCoefficients();
                        //just set from pre-evaluated quadrature point values for now
                        a = &q_a[eN_k * sd_rowptr.data()[nSpace]];
                        r = q_r[eN_k];
                        for (int I = 0; I < nSpace; I++)
                        {
                            f[I] = q_v[eN_k * nSpace + I] * u;
                            df[I] = q_v[eN_k * nSpace + I];
                        }
                        //
                        //moving mesh
                        //
                        /* double mesh_velocity[3]; */
                        /* mesh_velocity[0] = xt; */
                        /* mesh_velocity[1] = yt; */
                        /* mesh_velocity[2] = zt; */
                        /* for (int I=0;I<nSpace;I++) */
                        /*   { */
                        /*     f[I] -= MOVING_DOMAIN*m*mesh_velocity[I]; */
                        /*     df[I] -= MOVING_DOMAIN*dm*mesh_velocity[I]; */
                        /*   } */
                        //
                        //calculate time derivative at quadrature points
                        //
                        /* ck.bdf(alphaBDF, */
                        /*          q_m_betaBDF[eN_k], */
                        /*          m, */
                        /*          dm, */
                        /*          m_t, */
                        /*          dm_t); */
                        //
                        //calculate subgrid error (strong residual and adjoint)
                        //
                        //calculate strong residual
                        pdeResidual_u = ck.Advection_strong(df, grad_u) + ck.Reaction_strong(r); //ck.Mass_strong(m_t) + ck.Advection_strong(df,grad_u) + ck.Reaction_strong(r);
                        //calculate adjoint
                        for (int i = 0; i < nDOF_test_element; i++)
                        {
                            // register int eN_k_i_nSpace = (eN_k*nDOF_trial_element+i)*nSpace;
                            // Lstar_u[i]  = ck.Advection_adjoint(df,&u_grad_test_dV[eN_k_i_nSpace]);
                            int i_nSpace = i * nSpace;
                            Lstar_u[i] = ck.Advection_adjoint(df, &u_grad_test_dV[i_nSpace]);
                        }
                        //calculate tau and tau*Res
                        calculateSubgridError_tau(elementDiameter[eN], dm_t, df, cfl[eN_k], tau0);
                        calculateSubgridError_tau(Ct_sge,
                                                  G,
                                                  dm_t,
                                                  df,
                                                  tau1,
                                                  cfl[eN_k]);

                        tau = useMetrics * tau1 + (1.0 - useMetrics) * tau0;

                        subgridError_u = -tau * pdeResidual_u;
                        //
                        //calculate shock capturing diffusion
                        //
                        ck.calculateNumericalDiffusion(shockCapturingDiffusion, elementDiameter[eN], pdeResidual_u, grad_u, numDiff0);
                        ck.calculateNumericalDiffusion(shockCapturingDiffusion, sc_uref, sc_alpha, G, G_dd_G, pdeResidual_u, grad_u, numDiff1);
                        q_numDiff_u[eN_k] = useMetrics * numDiff1 + (1.0 - useMetrics) * numDiff0;
                        //
                        //update element residual
                        //
                        for (int i = 0; i < nDOF_test_element; i++)
                        {
                            int i_nSpace=i*nSpace;
                            elementResidual_u.data()[i] += ck.Advection_weak(f, &u_grad_test_dV[i_nSpace]) +
                                ck.Diffusion_weak(sd_rowptr.data(), sd_colind.data(), a, grad_u, &u_grad_test_dV[i_nSpace]) +
                                ck.Reaction_weak(r, u_test_dV[i]) +
                                ck.SubgridError(subgridError_u, Lstar_u[i]) +
                                ck.NumericalDiffusion(q_numDiff_u_last[eN_k], grad_u, &u_grad_test_dV[i_nSpace]);
                        }
                    }
                }

    void calculateResidual(//element
               xt::pyarray<double>& mesh_trial_ref,
               xt::pyarray<double>& mesh_grad_trial_ref,
               xt::pyarray<double>& mesh_dof,
               xt::pyarray<int>& mesh_l2g,
               xt::pyarray<double>& dV_ref,
               xt::pyarray<double>& u_trial_ref,
               xt::pyarray<double>& u_grad_trial_ref,
               xt::pyarray<double>& u_test_ref,
               xt::pyarray<double>& u_grad_test_ref,
               xt::pyarray<double>& elementDiameter,
               xt::pyarray<double>& cfl,
               double Ct_sge,
               double sc_uref,
               double sc_alpha,
               double useMetrics,
               //element boundary
               xt::pyarray<double>& mesh_trial_trace_ref,
               xt::pyarray<double>& mesh_grad_trial_trace_ref,
               xt::pyarray<double>& dS_ref,
               xt::pyarray<double>& u_trial_trace_ref,
               xt::pyarray<double>& u_grad_trial_trace_ref,
               xt::pyarray<double>& u_test_trace_ref,
               xt::pyarray<double>& u_grad_test_trace_ref,
               xt::pyarray<double>& normal_ref,
               xt::pyarray<double>& boundaryJac_ref,
               //physics
               int nElements_global,
               xt::pyarray<int>& u_l2g, 
               xt::pyarray<double>& u_dof,
               xt::pyarray<int>& sd_rowptr,
               xt::pyarray<int>& sd_colind,
               xt::pyarray<double>& q_a,
               xt::pyarray<double>& q_v,
               xt::pyarray<double>& q_r,
               int lag_shockCapturing,
               double shockCapturingDiffusion,
               xt::pyarray<double>& q_numDiff_u,
               xt::pyarray<double>& q_numDiff_u_last,
               int offset_u, int stride_u, 
               xt::pyarray<double>& globalResidual,               
               int nExteriorElementBoundaries_global,
               xt::pyarray<int>& exteriorElementBoundariesArray,
               xt::pyarray<int>& elementBoundaryElementsArray,
               xt::pyarray<int>& elementBoundaryLocalElementBoundariesArray,
               xt::pyarray<double>& ebqe_a,
               xt::pyarray<double>& ebqe_v,
               xt::pyarray<int>& isDOFBoundary_u,
               xt::pyarray<double>& ebqe_bc_u_ext,
               xt::pyarray<int>& isDiffusiveFluxBoundary_u,
               xt::pyarray<int>& isAdvectiveFluxBoundary_u,
               xt::pyarray<double>& ebqe_bc_flux_u_ext,
               xt::pyarray<double>& ebqe_bc_advectiveFlux_u_ext,
               xt::pyarray<double>& ebqe_penalty_ext,
               const double eb_adjoint_sigma)
    {
      //
      //loop over elements to compute volume integrals and load them into element and global residual
      //
      //eN is the element index
      //eN_k is the quadrature point index for a scalar
      //eN_k_nSpace is the quadrature point index for a vector
      //eN_i is the element test function index
      //eN_j is the element trial function index
      //eN_k_j is the quadrature point index for a trial function
      //eN_k_i is the quadrature point index for a trial function
      for(int eN=0;eN<nElements_global;eN++)
    {
      //declare local storage for element residual and initialize
      //register double elementResidual_u[nDOF_test_element],element_u[nDOF_trial_element];
          auto elementResidual_u = xt::pyarray<double>::from_shape({nDOF_test_element});
          auto element_u = xt::pyarray<double>::from_shape({nDOF_trial_element});
      for (int i=0;i<nDOF_test_element;i++)
        {
          register int eN_i=eN*nDOF_test_element+i;
          element_u.data()[i] = u_dof.data()[u_l2g.data()[eN_i]];
        }//i
      calculateElementResidual(mesh_trial_ref,
                   mesh_grad_trial_ref,
                   mesh_dof,
                   mesh_l2g,
                   dV_ref,
                   u_trial_ref,
                   u_grad_trial_ref,
                   u_test_ref,
                   u_grad_test_ref,
                   elementDiameter,
                   cfl,
                   Ct_sge,
                   sc_uref,
                   sc_alpha,
                   useMetrics,
                   mesh_trial_trace_ref,
                   mesh_grad_trial_trace_ref,
                   dS_ref,
                   u_trial_trace_ref,
                   u_grad_trial_trace_ref,
                   u_test_trace_ref,
                   u_grad_test_trace_ref,
                   normal_ref,
                   boundaryJac_ref,
                   nElements_global,
                   u_l2g, 
                   u_dof,
                   sd_rowptr,
                   sd_colind,
                   q_a,
                   q_v,
                   q_r,
                   lag_shockCapturing,
                   shockCapturingDiffusion,
                   q_numDiff_u,
                   q_numDiff_u_last,
                   offset_u,stride_u, 
                   elementResidual_u,
                   nExteriorElementBoundaries_global,
                   exteriorElementBoundariesArray,
                   elementBoundaryElementsArray,
                   elementBoundaryLocalElementBoundariesArray,
                   element_u,
                   eN);
      //
      //load element into global residual and save element residual
      //
      for(int i=0;i<nDOF_test_element;i++) 
        { 
          register int eN_i=eN*nDOF_test_element+i;
          
          globalResidual[offset_u+stride_u*u_l2g[eN_i]]+=elementResidual_u.data()[i];
        }//i
    }//elements
      //
      //loop over exterior element boundaries to calculate surface integrals and load into element and global residuals
      //
      //ebNE is the Exterior element boundary INdex
      //ebN is the element boundary INdex
      //eN is the element index
      for (int ebNE = 0; ebNE < nExteriorElementBoundaries_global; ebNE++) 
    { 
      register int ebN = exteriorElementBoundariesArray[ebNE], 
        eN  = elementBoundaryElementsArray[ebN*2+0],
        ebN_local = elementBoundaryLocalElementBoundariesArray[ebN*2+0],
        eN_nDOF_trial_element = eN*nDOF_trial_element;
      register double elementResidual_u[nDOF_test_element];
      for (int i=0;i<nDOF_test_element;i++)
        {
          elementResidual_u[i]=0.0;
        }
      for  (int kb=0;kb<nQuadraturePoints_elementBoundary;kb++) 
        { 
          register int ebNE_kb = ebNE*nQuadraturePoints_elementBoundary+kb,
        ebNE_kb_nSpace = ebNE_kb*nSpace,
        ebN_local_kb = ebN_local*nQuadraturePoints_elementBoundary+kb,
        ebN_local_kb_nSpace = ebN_local_kb*nSpace;
          register double u_ext=0.0,
        grad_u_ext[nSpace],
        m_ext=0.0,
        dm_ext=0.0,
        *a_ext,
        /* *da_exxt, */
        f_ext[nSpace],
        df_ext[nSpace],
        r_ext=0.0,
        /* dr_ext=0.0, */
        flux_diff_ext=0.0,
        flux_advect_ext=0.0,
        bc_u_ext=0.0,
        //bc_grad_u_ext[nSpace],
        bc_m_ext=0.0,
        bc_dm_ext=0.0,
        bc_f_ext[nSpace],
        bc_df_ext[nSpace],
        jac_ext[nSpace*nSpace],
        jacDet_ext,
        jacInv_ext[nSpace*nSpace],
        boundaryJac[nSpace*(nSpace-1)],
        metricTensor[(nSpace-1)*(nSpace-1)],
        metricTensorDetSqrt,
        dS,
        u_test_dS[nDOF_test_element],
        u_grad_trial_trace[nDOF_trial_element*nSpace],
        u_grad_test_dS[nDOF_trial_element*nSpace],
        normal[nSpace],x_ext,y_ext,z_ext,xt_ext,yt_ext,zt_ext,integralScaling,
        //
        G[nSpace*nSpace],G_dd_G,tr_G;
          // 
          //calculate the solution and gradients at quadrature points 
          // 
          //compute information about mapping from reference element to physical element
          ck.calculateMapping_elementBoundary(eN,
                          ebN_local,
                          kb,
                          ebN_local_kb,
                          mesh_dof.data(),
                          mesh_l2g.data(),
                          mesh_trial_trace_ref.data(),
                          mesh_grad_trial_trace_ref.data(),
                          boundaryJac_ref.data(),
                          jac_ext,
                          jacDet_ext,
                          jacInv_ext,
                          boundaryJac,
                          metricTensor,
                          metricTensorDetSqrt,
                          normal_ref.data(),
                          normal,
                          x_ext,y_ext,z_ext);
          /* ck.calculateMappingVelocity_elementBoundary(eN, */
          /*                           ebN_local, */
          /*                           kb, */
          /*                           ebN_local_kb, */
          /*                           mesh_velocity_dof, */
          /*                           mesh_l2g, */
          /*                           mesh_trial_trace_ref, */
          /*                           xt_ext,yt_ext,zt_ext, */
          /*                           normal, */
          /*                           boundaryJac, */
          /*                           metricTensor, */
          /*                           integralScaling); */
          /*dS = ((1.0-MOVING_DOMAIN)*metricTensorDetSqrt + MOVING_DOMAIN*integralScaling)*dS_ref[kb];*/
          dS = metricTensorDetSqrt*dS_ref[kb];
          //get the metric tensor
          //cek todo use symmetry
          ck.calculateG(jacInv_ext,G,G_dd_G,tr_G);
          //compute shape and solution information
          //shape
          ck.gradTrialFromRef(&u_grad_trial_trace_ref[ebN_local_kb_nSpace*nDOF_trial_element],jacInv_ext,u_grad_trial_trace);
          //solution and gradients    
          ck.valFromDOF(u_dof.data(),&u_l2g[eN_nDOF_trial_element],&u_trial_trace_ref[ebN_local_kb*nDOF_test_element],u_ext);
          ck.gradFromDOF(u_dof.data(),&u_l2g[eN_nDOF_trial_element],u_grad_trial_trace,grad_u_ext);
          //precalculate test function products with integration weights
          for (int j=0;j<nDOF_trial_element;j++)
        {
          u_test_dS[j] = u_test_trace_ref[ebN_local_kb*nDOF_test_element+j]*dS;
          for (int I=0;I<nSpace;I++)
            u_grad_test_dS[j*nSpace+I] = u_grad_trial_trace[j*nSpace+I]*dS;//cek hack, using trial
        }
          //
          //load the boundary values
          //
          bc_u_ext = isDOFBoundary_u[ebNE_kb]*ebqe_bc_u_ext[ebNE_kb]+(1-isDOFBoundary_u[ebNE_kb])*u_ext;
          //
          // 
          //calculate the pde coefficients using the solution and the boundary values for the solution 
          // 
          a_ext = &ebqe_a[ebNE_kb*sd_rowptr[nSpace]];
          for (int I=0;I<nSpace;I++)
        {
          f_ext[I] = ebqe_v[ebNE_kb*nSpace+I]*u_ext;
          df_ext[I] = ebqe_v[ebNE_kb*nSpace+I];
          bc_f_ext[I] = ebqe_v[ebNE_kb*nSpace+I]*bc_u_ext;
          bc_df_ext[I] = ebqe_v[ebNE_kb*nSpace+I];
        }
          /* evaluateCoefficients(&ebqe_velocity_ext[ebNE_kb_nSpace], */
          /*                u_ext, */
          /*                //VRANS */
          /*                porosity_ext, */
          /*                // */
          /*                m_ext, */
          /*                dm_ext, */
          /*                f_ext, */
          /*                df_ext); */
          /* evaluateCoefficients(&ebqe_velocity_ext[ebNE_kb_nSpace], */
          /*                bc_u_ext, */
          /*                //VRANS */
          /*                porosity_ext, */
          /*                // */
          /*                bc_m_ext, */
          /*                bc_dm_ext, */
          /*                bc_f_ext, */
          /*                bc_df_ext);     */
          //
          //moving mesh
          //
          /* double velocity_ext[nSpace]; */
          /* double mesh_velocity[3]; */
          /* mesh_velocity[0] = xt_ext; */
          /* mesh_velocity[1] = yt_ext; */
          /* mesh_velocity[2] = zt_ext; */
          /* for (int I=0;I<nSpace;I++) */
          /*     velocity_ext[I] = ebqe_velocity_ext[ebNE_kb_nSpace+0] - MOVING_DOMAIN*mesh_velocity[I]; */
          // 
          //calculate the numerical fluxes 
          // 
          exteriorNumericalDiffusiveFlux(sd_rowptr.data(),
                         sd_colind.data(),
                         isDOFBoundary_u[ebNE_kb],
                         isDiffusiveFluxBoundary_u[ebNE_kb],
                         normal,
                         a_ext,
                         bc_u_ext,
                         ebqe_bc_flux_u_ext[ebNE_kb],
                         a_ext,
                         grad_u_ext,
                         u_ext,
                         ebqe_penalty_ext[ebNE_kb],
                         flux_diff_ext);
          exteriorNumericalAdvectiveFlux(isDOFBoundary_u[ebNE_kb],
                               isAdvectiveFluxBoundary_u[ebNE_kb],
                               normal,
                               bc_u_ext,
                               ebqe_bc_flux_u_ext[ebNE_kb],
                               u_ext,
                               df_ext,
                               flux_advect_ext);
          //ebqe_flux[ebNE_kb] = flux_ext;
          //
          //update residuals
          //
          for (int i=0;i<nDOF_test_element;i++)
        {
          //int ebNE_kb_i = ebNE_kb*nDOF_test_element+i;
          elementResidual_u[i] += ck.ExteriorElementBoundaryFlux(flux_diff_ext+flux_advect_ext,u_test_dS[i])+
             ck.ExteriorElementBoundaryDiffusionAdjoint(isDOFBoundary_u[ebNE_kb],
                                    isDiffusiveFluxBoundary_u[ebNE_kb],
                                    eb_adjoint_sigma,
                                    u_ext,
                                    bc_u_ext,
                                    normal,
                                    sd_rowptr.data(),
                                    sd_colind.data(),
                                    a_ext,
                                    &u_grad_test_dS[i*nSpace]);
        }//i
        }//kb
      //
      //update the element and global residual storage
      //
      for (int i=0;i<nDOF_test_element;i++)
        {
          int eN_i = eN*nDOF_test_element+i;
          globalResidual[offset_u+stride_u*u_l2g[eN_i]] += elementResidual_u[i];
        }//i
    }//ebNE
    }

    inline void calculateElementJacobian(//element
                     xt::pyarray<double>& mesh_trial_ref,
                     xt::pyarray<double>& mesh_grad_trial_ref,
                     xt::pyarray<double>& mesh_dof,
                     xt::pyarray<int>& mesh_l2g,
                     xt::pyarray<double>& dV_ref,
                     xt::pyarray<double>& u_trial_ref,
                     xt::pyarray<double>& u_grad_trial_ref,
                     xt::pyarray<double>& u_test_ref,
                     xt::pyarray<double>& u_grad_test_ref,
                     xt::pyarray<double>& elementDiameter,
                     xt::pyarray<double>& cfl,
                     double Ct_sge,
                     double sc_uref,
                     double sc_alpha,
                     double useMetrics,
                     //element boundary
                     xt::pyarray<double>& mesh_trial_trace_ref,
                     xt::pyarray<double>& mesh_grad_trial_trace_ref,
                     xt::pyarray<double>& dS_ref,
                     xt::pyarray<double>& u_trial_trace_ref,
                     xt::pyarray<double>& u_grad_trial_trace_ref,
                     xt::pyarray<double>& u_test_trace_ref,
                     xt::pyarray<double>& u_grad_test_trace_ref,
                     xt::pyarray<double>& normal_ref,
                     xt::pyarray<double>& boundaryJac_ref,
                     //physics
                     int nElements_global,
                     xt::pyarray<int>& u_l2g,
                     xt::pyarray<double>& u_dof,
                     xt::pyarray<int>& sd_rowptr,
                     xt::pyarray<int>& sd_colind,
                     xt::pyarray<double>& q_a,
                     xt::pyarray<double>& q_v,
                     xt::pyarray<double>& q_r,
                     int lag_shockCapturing,
                     double shockCapturingDiffusion,
                     xt::pyarray<double>& q_numDiff_u,
                     xt::pyarray<double>& q_numDiff_u_last,
                     xt::pyarray<double>& elementJacobian_u_u,
                     xt::pyarray<double>& element_u,
                     int eN)
    {
      for (int i=0;i<nDOF_test_element;i++)
    for (int j=0;j<nDOF_trial_element;j++)
      {
        elementJacobian_u_u[i*nDOF_trial_element+j]=0.0;
      }
      for  (int k=0;k<nQuadraturePoints_element;k++)
    {
      int eN_k = eN*nQuadraturePoints_element+k; //index to a scalar at a quadrature point
      
      //declare local storage
      register double u=0.0,
        grad_u[nSpace],
        m=0.0,dm=0.0,
        f[nSpace],df[nSpace],
        m_t=0.0,dm_t=0.0,
        dpdeResidual_u_u[nDOF_trial_element],
        Lstar_u[nDOF_test_element],
        dsubgridError_u_u[nDOF_trial_element],
        tau=0.0,tau0=0.0,tau1=0.0,
        *a=NULL,
        dr=0.0,
        jac[nSpace*nSpace],
        jacDet,
        jacInv[nSpace*nSpace],
        u_grad_trial[nDOF_trial_element*nSpace],
        dV,
        u_test_dV[nDOF_test_element],
        u_grad_test_dV[nDOF_test_element*nSpace],
        x,y,z,
        G[nSpace*nSpace],G_dd_G,tr_G;
      //
      //calculate solution and gradients at quadrature points
      //
      ck.calculateMapping_element(eN,
                      k,
                      mesh_dof.data(),
                      mesh_l2g.data(),
                      mesh_trial_ref.data(),
                      mesh_grad_trial_ref.data(),
                      jac,
                      jacDet,
                      jacInv,
                      x,y,z);
      //get the physical integration weight
      dV = fabs(jacDet)*dV_ref[k];
      //get metric tensor and friends
      ck.calculateG(jacInv,G,G_dd_G,tr_G);
      //get the trial function gradients
      ck.gradTrialFromRef(&u_grad_trial_ref[k*nDOF_trial_element*nSpace],jacInv,u_grad_trial);
      //get the solution     
      ck.valFromElementDOF(element_u.data(),&u_trial_ref[k*nDOF_trial_element],u);
      //get the solution gradients
      ck.gradFromElementDOF(element_u.data(),u_grad_trial,grad_u);
      //precalculate test function products with integration weights
      for (int j=0;j<nDOF_trial_element;j++)
        {
          u_test_dV[j] = u_test_ref[k*nDOF_trial_element+j]*dV;
          for (int I=0;I<nSpace;I++)
        {
          u_grad_test_dV[j*nSpace+I]   = u_grad_trial[j*nSpace+I]*dV;//cek warning won't work for Petrov-Galerkin
        }
        }
      //
      //calculate pde coefficients and derivatives at quadrature points
      //
      //evaluateCoefficients()
      a = &q_a[eN_k*sd_rowptr.data()[nSpace]];
      for (int I=0;I<nSpace;I++)
        df[I] = q_v[eN_k*nSpace+I];
      dr = 0.0;

      //
      //calculate subgrid error contribution to the Jacobian (strong residual, adjoint, jacobian of strong residual)
      //
      //calculate the adjoint times the test functions
      for (int i=0;i<nDOF_test_element;i++)
        {
          // int eN_k_i_nSpace = (eN_k*nDOF_trial_element+i)*nSpace;
          // Lstar_u[i]=ck.Advection_adjoint(df,&u_grad_test_dV[eN_k_i_nSpace]);          
          register int i_nSpace = i*nSpace;
          Lstar_u[i]=ck.Advection_adjoint(df,&u_grad_test_dV[i_nSpace]);          
        }
      //calculate the Jacobian of strong residual
      for (int j=0;j<nDOF_trial_element;j++)
        {
          //int eN_k_j=eN_k*nDOF_trial_element+j;
          //int eN_k_j_nSpace = eN_k_j*nSpace;
          int j_nSpace = j*nSpace;
          dpdeResidual_u_u[j]= ck.MassJacobian_strong(dm_t,u_trial_ref[k*nDOF_trial_element+j]) +
        ck.AdvectionJacobian_strong(df,&u_grad_trial[j_nSpace]);
        }
      //tau and tau*Res
      calculateSubgridError_tau(elementDiameter[eN],
                    dm_t,
                    df,
                    cfl[eN_k],
                    tau0);
      
      calculateSubgridError_tau(Ct_sge,
                    G,
                    dm_t,
                    df,
                    tau1,
                    cfl[eN_k]);
      tau = useMetrics*tau1+(1.0-useMetrics)*tau0;
      
      for(int j=0;j<nDOF_trial_element;j++)
        dsubgridError_u_u[j] = -tau*dpdeResidual_u_u[j];

      for(int i=0;i<nDOF_test_element;i++)
        {
          int i_nSpace=i*nSpace;
          for(int j=0;j<nDOF_trial_element;j++) 
        { 
          int j_nSpace = j*nSpace;
          elementJacobian_u_u[i*nDOF_trial_element+j] += ck.AdvectionJacobian_weak(df,u_trial_ref[k*nDOF_trial_element+j],&u_grad_test_dV[i_nSpace]) +
            ck.SimpleDiffusionJacobian_weak(sd_rowptr.data(),sd_colind.data(),a,&u_grad_trial[j_nSpace],&u_grad_test_dV[i_nSpace]) +
            ck.ReactionJacobian_weak(dr,u_trial_ref[k*nDOF_trial_element+j],u_test_dV[i]) +
            ck.SubgridErrorJacobian(dsubgridError_u_u[j],Lstar_u[i]) +
            ck.NumericalDiffusionJacobian(q_numDiff_u_last[eN_k],&u_grad_trial[j_nSpace],&u_grad_test_dV[i_nSpace]);              
        }//j
        }//i
    }//k
    }
    void calculateJacobian(//element
               xt::pyarray<double>& mesh_trial_ref,
               xt::pyarray<double>& mesh_grad_trial_ref,
               xt::pyarray<double>& mesh_dof,
               xt::pyarray<int>& mesh_l2g,
               xt::pyarray<double>& dV_ref,
               xt::pyarray<double>& u_trial_ref,
               xt::pyarray<double>& u_grad_trial_ref,
               xt::pyarray<double>& u_test_ref,
               xt::pyarray<double>& u_grad_test_ref,
               xt::pyarray<double>& elementDiameter,
               xt::pyarray<double>& cfl,
               double Ct_sge,
               double sc_uref,
               double sc_alpha,
               double useMetrics,
               //element boundary
               xt::pyarray<double>& mesh_trial_trace_ref,
               xt::pyarray<double>& mesh_grad_trial_trace_ref,
               xt::pyarray<double>& dS_ref,
               xt::pyarray<double>& u_trial_trace_ref,
               xt::pyarray<double>& u_grad_trial_trace_ref,
               xt::pyarray<double>& u_test_trace_ref,
               xt::pyarray<double>& u_grad_test_trace_ref,
               xt::pyarray<double>& normal_ref,
               xt::pyarray<double>& boundaryJac_ref,
               //physics
               int nElements_global,
               xt::pyarray<int>& u_l2g,
               xt::pyarray<double>& u_dof,
               xt::pyarray<int>& sd_rowptr,
               xt::pyarray<int>& sd_colind,
               xt::pyarray<double>& q_a,
               xt::pyarray<double>& q_v,
               xt::pyarray<double>& q_r,
               int lag_shockCapturing,
               double shockCapturingDiffusion,
               xt::pyarray<double>& q_numDiff_u,
               xt::pyarray<double>& q_numDiff_u_last,
               xt::pyarray<int>& csrRowIndeces_u_u,xt::pyarray<int>& csrColumnOffsets_u_u,
               xt::pyarray<double>& globalJacobian,
               int nExteriorElementBoundaries_global,
               xt::pyarray<int>& exteriorElementBoundariesArray,
               xt::pyarray<int>& elementBoundaryElementsArray,
               xt::pyarray<int>& elementBoundaryLocalElementBoundariesArray,
               xt::pyarray<double>& ebqe_a,
               xt::pyarray<double>& ebqe_v,
               xt::pyarray<int>& isDOFBoundary_u,
               xt::pyarray<double>& ebqe_bc_u_ext,
               xt::pyarray<int>& isDiffusiveFluxBoundary_u,
               xt::pyarray<int>& isAdvectiveFluxBoundary_u,
               xt::pyarray<double>& ebqe_bc_flux_u_ext,
               xt::pyarray<double>& ebqe_bc_advectiveFlux_u_ext,
               xt::pyarray<int>& csrColumnOffsets_eb_u_u,
               xt::pyarray<double>& ebqe_penalty_ext,
               const double eb_adjoint_sigma)
               {
                   //
                   //loop over elements to compute volume integrals and load them into the element Jacobians and global Jacobian
                   //
                   for(int eN=0;eN<nElements_global;eN++)
                   {
                       //register double  elementJacobian_u_u[nDOF_test_element*nDOF_trial_element],element_u[nDOF_trial_element];
                       auto elementJacobian_u_u = xt::pyarray<double>::from_shape({nDOF_test_element*nDOF_trial_element});
                       auto element_u = xt::pyarray<double>::from_shape({nDOF_trial_element});
                       for (int j=0;j<nDOF_trial_element;j++)
                       {
                           register int eN_j = eN*nDOF_trial_element+j;
                           element_u[j] = u_dof[u_l2g[eN_j]];
                       }
                       calculateElementJacobian(mesh_trial_ref,
                               mesh_grad_trial_ref,
                               mesh_dof,
                               mesh_l2g,
                               dV_ref,
                               u_trial_ref,
                               u_grad_trial_ref,
                               u_test_ref,
                               u_grad_test_ref,
                               elementDiameter,
                               cfl,
                               Ct_sge,
                               sc_uref,
                               sc_alpha,
                               useMetrics,
                               mesh_trial_trace_ref,
                               mesh_grad_trial_trace_ref,
                               dS_ref,
                               u_trial_trace_ref,
                               u_grad_trial_trace_ref,
                               u_test_trace_ref,
                               u_grad_test_trace_ref,
                               normal_ref,
                               boundaryJac_ref,
                               nElements_global,
                               u_l2g,
                               u_dof,
                               sd_rowptr,
                               sd_colind,
                               q_a,
                               q_v,
                               q_r,
                               lag_shockCapturing,
                               shockCapturingDiffusion,
                               q_numDiff_u,
                               q_numDiff_u_last,
                               elementJacobian_u_u,
                               element_u,
                               eN);
                       //
                       //load into element Jacobian into global Jacobian
                       //
                       for (int i=0;i<nDOF_test_element;i++)
                       {
                           int eN_i = eN*nDOF_test_element+i;
                           for (int j=0;j<nDOF_trial_element;j++)
                           {
                               int eN_i_j = eN_i*nDOF_trial_element+j;
                               globalJacobian.data()[csrRowIndeces_u_u[eN_i] + csrColumnOffsets_u_u[eN_i_j]] += elementJacobian_u_u[i*nDOF_trial_element+j];
                           }//j
                       }//i
                   }//elements
                   //
                   //loop over exterior element boundaries to compute the surface integrals and load them into the global Jacobian
                   //
                   for (int ebNE = 0; ebNE < nExteriorElementBoundaries_global; ebNE++) 
                   { 
                       register int ebN = exteriorElementBoundariesArray[ebNE]; 
                       register int eN  = elementBoundaryElementsArray[ebN*2+0],
                       ebN_local = elementBoundaryLocalElementBoundariesArray[ebN*2+0],
                       eN_nDOF_trial_element = eN*nDOF_trial_element;
                       for  (int kb=0;kb<nQuadraturePoints_elementBoundary;kb++) 
                       { 
                           register int ebNE_kb = ebNE*nQuadraturePoints_elementBoundary+kb,
                                    ebNE_kb_nSpace = ebNE_kb*nSpace,
                                    ebN_local_kb = ebN_local*nQuadraturePoints_elementBoundary+kb,
                                    ebN_local_kb_nSpace = ebN_local_kb*nSpace;

                           register double u_ext=0.0,
                                    grad_u_ext[nSpace],
                                    m_ext=0.0,
                                    dm_ext=0.0,
                                    *a_ext,
                                    f_ext[nSpace],
                                    df_ext[nSpace],
                                    r_ext=0.0,
                                    dflux_u_u_ext=0.0,
                                    bc_u_ext=0.0,
                                    //bc_grad_u_ext[nSpace],
                                    bc_m_ext=0.0,
                                    bc_dm_ext=0.0,
                                    bc_f_ext[nSpace],
                                    bc_df_ext[nSpace],
                                    fluxJacobian_u_u[nDOF_trial_element],
                                    jac_ext[nSpace*nSpace],
                                    jacDet_ext,
                                    jacInv_ext[nSpace*nSpace],
                                    boundaryJac[nSpace*(nSpace-1)],
                                    metricTensor[(nSpace-1)*(nSpace-1)],
                                    metricTensorDetSqrt,
                                    dS,
                                    u_test_dS[nDOF_test_element],
                                    u_grad_trial_trace[nDOF_trial_element*nSpace],
                                    u_grad_test_dS[nDOF_trial_element*nSpace],
                                    normal[nSpace],x_ext,y_ext,z_ext,xt_ext,yt_ext,zt_ext,integralScaling,
                                    //
                                    G[nSpace*nSpace],G_dd_G,tr_G;
                                    // 
                                    //calculate the solution and gradients at quadrature points 
                                    // 
                                    // u_ext=0.0;
                                    // for (int I=0;I<nSpace;I++)
                                    //   {
                                    //     grad_u_ext[I] = 0.0;
                                    //     bc_grad_u_ext[I] = 0.0;
                                    //   }
                                    // for (int j=0;j<nDOF_trial_element;j++) 
                                    //   { 
                                    //     register int eN_j = eN*nDOF_trial_element+j,
                                    //       ebNE_kb_j = ebNE_kb*nDOF_trial_element+j,
                                    //       ebNE_kb_j_nSpace= ebNE_kb_j*nSpace;
                                    //     u_ext += valFromDOF_c(u_dof[u_l2g[eN_j]],u_trial_ext[ebNE_kb_j]); 

                                    //     for (int I=0;I<nSpace;I++)
                                    //       {
                                    //         grad_u_ext[I] += gradFromDOF_c(u_dof[u_l2g[eN_j]],u_grad_trial_ext[ebNE_kb_j_nSpace+I]); 
                                    //       } 
                                    //   }
                                    ck.calculateMapping_elementBoundary(eN,
                                            ebN_local,
                                            kb,
                                            ebN_local_kb,
                                            mesh_dof.data(),
                                            mesh_l2g.data(),
                                            mesh_trial_trace_ref.data(),
                                            mesh_grad_trial_trace_ref.data(),
                                            boundaryJac_ref.data(),
                                            jac_ext,
                                            jacDet_ext,
                                            jacInv_ext,
                                            boundaryJac,
                                            metricTensor,
                                            metricTensorDetSqrt,
                                            normal_ref.data(),
                                            normal,
                                            x_ext,y_ext,z_ext);
                                    /* ck.calculateMappingVelocity_elementBoundary(eN, */
                                    /*                           ebN_local, */
                                    /*                           kb, */
                                    /*                           ebN_local_kb, */
                                    /*                           mesh_velocity_dof, */
                                    /*                           mesh_l2g, */
                                    /*                           mesh_trial_trace_ref, */
                                    /*                           xt_ext,yt_ext,zt_ext, */
                                    /*                           normal, */
                                    /*                           boundaryJac, */
                                    /*                           metricTensor, */
                                    /*                           integralScaling); */
                                    /* dS = ((1.0-MOVING_DOMAIN)*metricTensorDetSqrt + MOVING_DOMAIN*integralScaling)*dS_ref[kb]; */
                                    dS = metricTensorDetSqrt*dS_ref[kb];
                                    //dS = metricTensorDetSqrt*dS_ref[kb];
                                    ck.calculateG(jacInv_ext,G,G_dd_G,tr_G);
                                    //compute shape and solution information
                                    //shape
                                    ck.gradTrialFromRef(&u_grad_trial_trace_ref[ebN_local_kb_nSpace*nDOF_trial_element],jacInv_ext,u_grad_trial_trace);
                                    //solution and gradients    
                                    ck.valFromDOF(u_dof.data(),&u_l2g[eN_nDOF_trial_element],&u_trial_trace_ref[ebN_local_kb*nDOF_test_element],u_ext);
                                    ck.gradFromDOF(u_dof.data(),&u_l2g[eN_nDOF_trial_element],u_grad_trial_trace,grad_u_ext);
                                    //precalculate test function products with integration weights
                                    for (int j=0;j<nDOF_trial_element;j++)
                                    {
                                        u_test_dS[j] = u_test_trace_ref[ebN_local_kb*nDOF_test_element+j]*dS;
                                        for (int I=0;I<nSpace;I++)
                                            u_grad_test_dS[j*nSpace+I] = u_grad_trial_trace[j*nSpace+I]*dS;//cek hack, using trial
                                    }
                                    //
                                    //load the boundary values
                                    //
                                    bc_u_ext = isDOFBoundary_u[ebNE_kb]*ebqe_bc_u_ext[ebNE_kb]+(1-isDOFBoundary_u[ebNE_kb])*u_ext;
                                    // 
                                    //calculate the internal and external trace of the pde coefficients 
                                    // 
                                    /* evaluateCoefficients(&ebqe_velocity_ext[ebNE_kb_nSpace], */
                                    /*                u_ext, */
                                    /*                //VRANS */
                                    /*                porosity_ext, */
                                    /*                // */
                                    /*                m_ext, */
                                    /*                dm_ext, */
                                    /*                f_ext, */
                                    /*                df_ext); */
                                    /* evaluateCoefficients(&ebqe_velocity_ext[ebNE_kb_nSpace], */
                                    /*                bc_u_ext, */
                                    /*                //VRANS */
                                    /*                porosity_ext, */
                                    /*                // */
                                    /*                bc_m_ext, */
                                    /*                bc_dm_ext, */
                                    /*                bc_f_ext, */
                                    /*                bc_df_ext); */
                                    a_ext = &ebqe_a[ebNE_kb*sd_rowptr.data()[nSpace]];
                                    for (int I=0;I<nSpace;I++)
                                    {
                                        df_ext[I] = ebqe_v[ebNE_kb*nSpace+I];
                                        bc_df_ext[I] = ebqe_v[ebNE_kb*nSpace+I];
                                    }
                                    //
                                    //moving domain
                                    //
                                    /* double velocity_ext[nSpace]; */
                                    /* double mesh_velocity[3]; */
                                    /* for (int I=0;I<nSpace;I++) */
                                    /*     velocity_ext[I] = ebqe_velocity_ext[ebNE_kb_nSpace+0];// - MOVING_DOMAIN*mesh_velocity[I]; */
                                    // 
                                    //calculate the numerical fluxes 
                                    // 
                                    exteriorNumericalAdvectiveFluxDerivative(isDOFBoundary_u[ebNE_kb],
                                            isAdvectiveFluxBoundary_u[ebNE_kb],
                                            normal,
                                            df_ext,
                                            dflux_u_u_ext);
                                    //
                                    //calculate the flux jacobian
                                    //
                                    for (int j=0;j<nDOF_trial_element;j++)
                                    {
                                        //register int ebNE_kb_j = ebNE_kb*nDOF_trial_element+j;
                                        register int j_nSpace = j*nSpace,ebN_local_kb_j=ebN_local_kb*nDOF_trial_element+j;
                                        fluxJacobian_u_u[j]=ExteriorNumericalDiffusiveFluxJacobian(sd_rowptr.data(),
                                                sd_colind.data(),
                                                isDOFBoundary_u[ebNE_kb],
                                                isDiffusiveFluxBoundary_u[ebNE_kb],
                                                normal,
                                                a_ext,
                                                u_trial_trace_ref[ebN_local_kb_j],
                                                &u_grad_trial_trace[j_nSpace],
                                                ebqe_penalty_ext[ebNE_kb]) + 
                                            ck.ExteriorNumericalAdvectiveFluxJacobian(dflux_u_u_ext,u_trial_trace_ref[ebN_local_kb_j]);
                                    }//j
                                    //
                                    //update the global Jacobian from the flux Jacobian
                                    //
                                    for (int i=0;i<nDOF_test_element;i++)
                                    {
                                        register int eN_i = eN*nDOF_test_element+i;
                                        register int i_nSpace = i*nSpace;
                                        //register int ebNE_kb_i = ebNE_kb*nDOF_test_element+i;
                                        for (int j=0;j<nDOF_trial_element;j++)
                                        {
                                            register int ebN_i_j = ebN*4*nDOF_test_X_trial_element + i*nDOF_trial_element + j;
                                            register int ebN_local_kb_j=ebN_local_kb*nDOF_trial_element+j;

                                            globalJacobian.data()[csrRowIndeces_u_u[eN_i] + csrColumnOffsets_eb_u_u[ebN_i_j]] += fluxJacobian_u_u[j]*u_test_dS[i]+
                                                ck.ExteriorElementBoundaryDiffusionAdjointJacobian(isDOFBoundary_u[ebNE_kb],
                                                        isDiffusiveFluxBoundary_u[ebNE_kb],
                                                        eb_adjoint_sigma,
                                                        u_trial_trace_ref[ebN_local_kb_j],
                                                        normal,
                                                        sd_rowptr.data(),
                                                        sd_colind.data(),
                                                        a_ext,
                                                        &u_grad_test_dS[i_nSpace]);
                                        }//j
                                    }//i
                       }//kb
                   }//ebNE
               }//computeJacobian
    };//cppADR

  inline cppADR_base* newADR(int nSpaceIn,
                 int nQuadraturePoints_elementIn,
                 int nDOF_mesh_trial_elementIn,
                 int nDOF_trial_elementIn,
                 int nDOF_test_elementIn,
                 int nQuadraturePoints_elementBoundaryIn,
                 int CompKernelFlag)
  {
    if (nSpaceIn == 2)
      return proteus::chooseAndAllocateDiscretization2D<cppADR_base,cppADR,CompKernel>(nSpaceIn,
                                               nQuadraturePoints_elementIn,
                                               nDOF_mesh_trial_elementIn,
                                               nDOF_trial_elementIn,
                                               nDOF_test_elementIn,
                                               nQuadraturePoints_elementBoundaryIn,
                                               CompKernelFlag);
    else
      return proteus::chooseAndAllocateDiscretization<cppADR_base,cppADR,CompKernel>(nSpaceIn,
                                             nQuadraturePoints_elementIn,
                                             nDOF_mesh_trial_elementIn,
                                             nDOF_trial_elementIn,
                                             nDOF_test_elementIn,
                                             nQuadraturePoints_elementBoundaryIn,
                                             CompKernelFlag);
  }
}//proteus
#endif
