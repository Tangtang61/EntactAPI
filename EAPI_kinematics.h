#pragma once

#include <math.h>


/******************************************************************************* 
W5D Kinematics Functions
********************************************************************************/
int forwardKinematics_w5d(double *q, double *task)
{

	double PI = 3.1415926536;
	double phi = PI/4;
	double L1 = 67.5;
	double L2 = 45;
	double L3 = 12.5;
	double L4 = 160;
	
	double t1 = cos(q[5]);
	double t2 = q[3] + phi;
	double t3 = sin(t2);
	double t5 = q[4] + phi;
	double t6 = cos(t5);
	double t8 = -L3 + t3 * L4 + t6 * L4;
	double t9 = t1 * t8;
	double t11 = sin(q[5]);
	double t12 = t11 * L2;
	double t14 = cos(q[2]);
	double t15 = q[0] + phi;
	double t16 = sin(t15);
	double t18 = q[1] + phi;
	double t19 = cos(t18);
	double t21 = -L3 + t16 * L4 + t19 * L4;
	double t22 = t14 * t21;
	double t24 = sin(q[2]);
	double t25 = t24 * L2;
	double t28 = cos(t2);
	double t29 = t28 * L4;
	double t31 = sin(t5);
	double t32 = t31 * L4;
	double t34 = cos(t15);
	double t35 = t34 * L4;
	double t37 = sin(t18);
	double t38 = t37 * L4;
	double t41 = t11 * t8;
	double t43 = t1 * L2;
	double t45 = t24 * t21;
	double t47 = t14 * L2;
	double t50 = q[6] + phi;
	double t51 = cos(t50);
	double t52 = t22 - t25 - t9 - t12;
	double t53 = t52 * t52;
	double t54 = -t35 + t38 + t29 - t32;
	double t55 = t54 * t54;
	double t57 = (double) (2 * L1) - t45 - t47 + t41 - t43;
	double t58 = t57 * t57;
	double t60 = sqrt(t53 + t55 + t58);
	double t61 = 0.1e1 / t60;
	double t62 = t31 * t61;
	double t64 = t11 * t6;
	double t65 = t61 * t54;
	double t67 = t62 * t57 + t64 * t65;
	double t69 = sin(t50);
	double t70 = t1 * t6;
	double t73 = t70 * t65 - t62 * t52;
	double t75 = t61 * t57;
	double t76 = t61 * t52;
	double t79 = -t64 * t76 - t70 * t75;
	double t81 = t65 * t73 - t75 * t79;
	double t90 = t75 * t67 - t76 * t73;
	double t99 = t76 * t79 - t65 * t67;

	task[0] = 0.5e0 * t9 + 0.5e0 * t12 + 0.5e0 * t22 - 0.5e0 * t25;
	task[1] = -0.5e0 * t29 + 0.5e0 * t32 - 0.5e0 * t35 + 0.5e0 * t38;
	task[2] = -0.5e0 * t41 + 0.5e0 * t43 - 0.5e0 * t45 - 0.5e0 * t47;
	task[3] = t51 * t67 + t69 * t81;
	task[4] = -t69 * t67 + t51 * t81;
	task[5] = t76;
	task[6] = t51 * t79 + t69 * t90;
	task[7] = -t69 * t79 + t51 * t90;
	task[8] = t65;
	task[9] = t51 * t73 + t69 * t99;
	task[10] = -t69 * t73 + t51 * t99;
	task[11] = t75;
	// End W5D Forward Kinematics
	
	return 1;
}

int velocityKinematics_w5d(double *q, double *qd, double *vel)
{
	double jacobian[6][7];
	double PI = 3.1415926536;
	double phi = PI/4;
	double L1 = 67.5;
	double L2 = 45;
	double L3 = 12.5;
	double L4 = 160;
	
	double t1 = cos(q[2]);
	double t2 = q[0] + phi;
	double t3 = cos(t2);
	double t5 = t1 * t3 * L4;
	double t7 = q[1] + phi;
	double t8 = sin(t7);
	double t10 = t1 * t8 * L4;
	double t12 = sin(q[2]);
	double t13 = sin(t2);
	double t14 = t13 * L4;
	double t15 = cos(t7);
	double t16 = t15 * L4;
	double t17 = -L3 + t14 + t16;
	double t18 = t12 * t17;
	double t20 = t1 * L2;
	double t23 = cos(q[5]);
	double t24 = q[3] + phi;
	double t25 = cos(t24);
	double t27 = t23 * t25 * L4;
	double t29 = q[4] + phi;
	double t30 = sin(t29);
	double t31 = t23 * t30;
	double t34 = sin(q[5]);
	double t35 = sin(t24);
	double t36 = t35 * L4;
	double t37 = cos(t29);
	double t38 = t37 * L4;
	double t39 = -L3 + t36 + t38;
	double t40 = t34 * t39;
	double t42 = t23 * L2;
	double t50 = t12 * t3 * L4;
	double t53 = t12 * t8 * L4;
	double t55 = t1 * t17;
	double t57 = t12 * L2;
	double t61 = t34 * t25 * L4;
	double t63 = t34 * t30;
	double t66 = t23 * t39;
	double t68 = t34 * L2;
	double t71 = q[6] + phi;
	double t72 = cos(t71);
	double t73 = t23 * t37;
	double t74 = t55 - t57 - t66 - t68;
	double t75 = t74 * t74;
	double t76 = t3 * L4;
	double t77 = t8 * L4;
	double t78 = t25 * L4;
	double t79 = t30 * L4;
	double t80 = -t76 + t77 + t78 - t79;
	double t81 = t80 * t80;
	double t83 = (double) (2 * L1) - t18 - t20 + t40 - t42;
	double t84 = t83 * t83;
	double t85 = t75 + t81 + t84;
	double t86 = sqrt(t85);
	double t88 = 0.1e1 / t86 / t85;
	double t89 = t88 * t80;
	double t90 = t74 * t1;
	double t94 = t83 * t12;
	double t96 = t90 * t76 + t80 * t13 * L4 - t94 * t76;
	double t97 = 0.2e1 * t89 * t96;
	double t100 = 0.1e1 / t86;
	double t101 = t100 * t13;
	double t102 = t101 * L4;
	double t104 = t30 * t88;
	double t108 = t30 * t100;
	double t110 = -t73 * t97 / 0.2e1 + t73 * t102 + t104 * t74 * t96 - t108 * t5;
	double t112 = sin(t71);
	double t113 = t88 * t74;
	double t114 = t34 * t37;
	double t115 = t100 * t74;
	double t117 = t100 * t83;
	double t119 = -t114 * t115 - t73 * t117;
	double t120 = 0.2e1 * t119 * t96;
	double t123 = t100 * t1;
	double t124 = t76 * t119;
	double t126 = 0.2e1 * t113 * t96;
	double t129 = t114 * t100;
	double t131 = t88 * t83;
	double t132 = 0.2e1 * t131 * t96;
	double t135 = t73 * t100;
	double t137 = t114 * t126 / 0.2e1 - t129 * t5 + t73 * t132 / 0.2e1 + t135 * t50;
	double t140 = t100 * t80;
	double t141 = t114 * t140;
	double t142 = t108 * t83 + t141;
	double t143 = 0.2e1 * t142 * t96;
	double t146 = L4 * t142;
	double t155 = -t104 * t83 * t96 - t108 * t50 - t114 * t97 / 0.2e1 + t114 * t102;
	double t157 = -t113 * t120 / 0.2e1 + t123 * t124 + t115 * t137 + t89 * t143 / 0.2e1 - t101 * t146 - t140 * t155;
	double t162 = t73 * t140;
	double t164 = t162 - t108 * t74;
	double t166 = t117 * t142 - t115 * t164;
	double t168 = t72 * t119 + t112 * t166;
	double t175 = -t112 * t119 + t72 * t166;
	double t178 = t100 * t12;
	double t188 = -t90 * t77 + t80 * t15 * L4 + t94 * t77;
	double t189 = 0.2e1 * t89 * t188;
	double t192 = t100 * t15;
	double t193 = t192 * L4;
	double t199 = -t73 * t189 / 0.2e1 + t73 * t193 + t104 * t74 * t188 + t108 * t10;
	double t201 = 0.2e1 * t119 * t188;
	double t204 = t77 * t119;
	double t206 = 0.2e1 * t113 * t188;
	double t210 = 0.2e1 * t131 * t188;
	double t214 = t114 * t206 / 0.2e1 + t129 * t10 + t73 * t210 / 0.2e1 - t135 * t53;
	double t216 = 0.2e1 * t142 * t188;
	double t227 = -t104 * t83 * t188 + t108 * t53 - t114 * t189 / 0.2e1 + t114 * t193;
	double t229 = -t113 * t201 / 0.2e1 - t123 * t204 + t115 * t214 + t89 * t216 / 0.2e1 - t192 * t146 - t140 * t227;
	double t243 = -t18 - t20;
	double t245 = -t55 + t57;
	double t247 = t74 * t243 + t83 * t245;
	double t248 = 0.2e1 * t89 * t247;
	double t251 = 0.2e1 * t74 * t247;
	double t255 = -t73 * t248 / 0.2e1 + t104 * t251 / 0.2e1 - t108 * t243;
	double t257 = 0.2e1 * t119 * t247;
	double t260 = t100 * t243;
	double t262 = 0.2e1 * t113 * t247;
	double t266 = 0.2e1 * t131 * t247;
	double t269 = t100 * t245;
	double t271 = t114 * t262 / 0.2e1 - t114 * t260 + t73 * t266 / 0.2e1 - t73 * t269;
	double t273 = 0.2e1 * t142 * t247;
	double t282 = -t104 * t83 * t247 + t108 * t245 - t114 * t248 / 0.2e1;
	double t284 = -t113 * t257 / 0.2e1 + t260 * t119 + t115 * t271 + t89 * t273 / 0.2e1 - t140 * t282;
	double t297 = t74 * t23;
	double t301 = t83 * t34;
	double t303 = -t297 * t78 - t80 * t35 * L4 + t301 * t78;
	double t304 = 0.2e1 * t89 * t303;
	double t307 = t100 * t35;
	double t308 = t307 * L4;
	double t314 = -t73 * t304 / 0.2e1 - t73 * t308 + t104 * t74 * t303 + t108 * t27;
	double t316 = 0.2e1 * t119 * t303;
	double t319 = t100 * t23;
	double t320 = t78 * t119;
	double t322 = 0.2e1 * t113 * t303;
	double t324 = 0.2e1 * t131 * t303;
	double t326 = t114 * t322 + t73 * t324;
	double t328 = 0.2e1 * t142 * t303;
	double t339 = -t104 * t83 * t303 + t108 * t61 - t114 * t304 / 0.2e1 - t114 * t308;
	double t341 = -t113 * t316 / 0.2e1 - t319 * t320 + t115 * t326 / 0.2e1 + t89 * t328 / 0.2e1 + t307 * t146 - t140 * t339;
	double t350 = t100 * t34;
	double t361 = t297 * t79 - t80 * t37 * L4 - t301 * t79;
	double t362 = 0.2e1 * t89 * t361;
	double t365 = t37 * t37;
	double t367 = t100 * L4;
	double t369 = t37 * t100;
	double t374 = t30 * t30;
	double t375 = t374 * t100;
	double t378 = -t31 * t140 - t73 * t362 / 0.2e1 - t23 * t365 * t367 - t369 * t74 + t104 * t74 * t361 - t375 * t23 * L4;
	double t380 = 0.2e1 * t119 * t361;
	double t383 = t79 * t119;
	double t386 = 0.2e1 * t113 * t361;
	double t390 = 0.2e1 * t131 * t361;
	double t393 = t63 * t115 + t114 * t386 / 0.2e1 + t31 * t117 + t73 * t390 / 0.2e1;
	double t395 = 0.2e1 * t142 * t361;
	double t410 = t369 * t83 - t104 * t83 * t361 - t375 * t34 * L4 - t63 * t140 - t114 * t362 / 0.2e1 - t34 * t365 * t367;
	double t412 = -t113 * t380 / 0.2e1 + t319 * t383 + t115 * t393 + t89 * t395 / 0.2e1 + t369 * t146 - t140 * t410;
	double t426 = t40 - t42;
	double t428 = t66 + t68;
	double t430 = t74 * t426 + t83 * t428;
	double t431 = 0.2e1 * t89 * t430;
	double t434 = 0.2e1 * t74 * t430;
	double t438 = -t141 - t73 * t431 / 0.2e1 + t104 * t434 / 0.2e1 - t108 * t426;
	double t440 = 0.2e1 * t119 * t430;
	double t443 = t100 * t426;
	double t446 = 0.2e1 * t113 * t430;
	double t451 = 0.2e1 * t131 * t430;
	double t454 = t100 * t428;
	double t456 = -t73 * t115 + t114 * t446 / 0.2e1 - t114 * t443 + t114 * t117 + t73 * t451 / 0.2e1 - t73 * t454;
	double t458 = 0.2e1 * t142 * t430;
	double t467 = -t104 * t83 * t430 + t108 * t428 + t162 - t114 * t431 / 0.2e1;
	double t469 = -t113 * t440 / 0.2e1 + t443 * t119 + t115 * t456 + t89 * t458 / 0.2e1 - t140 * t467;
	double t485 = t115 * t119 - t140 * t142;
	double t487 = -t112 * t164 + t72 * t485;
	double t491 = -t72 * t164 - t112 * t485;
	double t495 = 0.2e1 * t164 * t96;
	double t498 = L4 * t164;
	double t505 = -t89 * t495 / 0.2e1 + t101 * t498 + t140 * t110 + t131 * t120 / 0.2e1 + t178 * t124 - t117 * t137;
	double t520 = 0.2e1 * t164 * t188;
	double t529 = -t89 * t520 / 0.2e1 + t192 * t498 + t140 * t199 + t131 * t201 / 0.2e1 - t178 * t204 - t117 * t214;
	double t544 = 0.2e1 * t164 * t247;
	double t552 = -t89 * t544 / 0.2e1 + t140 * t255 + t131 * t257 / 0.2e1 - t269 * t119 - t117 * t271;
	double t566 = 0.2e1 * t164 * t303;
	double t575 = -t89 * t566 / 0.2e1 - t307 * t498 + t140 * t314 + t131 * t316 / 0.2e1 - t350 * t320 - t117 * t326 / 0.2e1;
	double t590 = 0.2e1 * t164 * t361;
	double t599 = -t89 * t590 / 0.2e1 - t369 * t498 + t140 * t378 + t131 * t380 / 0.2e1 + t350 * t383 - t117 * t393;
	double t614 = 0.2e1 * t164 * t430;
	double t622 = -t89 * t614 / 0.2e1 + t140 * t438 + t131 * t440 / 0.2e1 - t454 * t119 - t117 * t456;
	double t638 = t140 * t164 - t117 * t119;
	double t640 = -t112 * t142 + t72 * t638;
	double t644 = -t72 * t142 - t112 * t638;
	double t658 = -t131 * t143 / 0.2e1 - t178 * t76 * t142 + t117 * t155 + t113 * t495 / 0.2e1 - t123 * t76 * t164 - t115 * t110;
	double t682 = -t131 * t216 / 0.2e1 + t178 * t77 * t142 + t117 * t227 + t113 * t520 / 0.2e1 + t123 * t77 * t164 - t115 * t199;
	double t704 = -t131 * t273 / 0.2e1 + t269 * t142 + t117 * t282 + t113 * t544 / 0.2e1 - t260 * t164 - t115 * t255;
	double t712 = t85 * t85;
	double t714 = 0.1e1 / t712 * t80;
	double t729 = -t131 * t328 / 0.2e1 + t350 * t78 * t142 + t117 * t339 + t113 * t566 / 0.2e1 + t319 * t78 * t164 - t115 * t314;
	double t753 = -t131 * t395 / 0.2e1 - t350 * t79 * t142 + t117 * t410 + t113 * t590 / 0.2e1 - t319 * t79 * t164 - t115 * t378;
	double t776 = -t131 * t458 / 0.2e1 + t454 * t142 + t117 * t467 + t113 * t614 / 0.2e1 - t443 * t164 - t115 * t438;
	jacobian[0][0] = 0.5e0 * t5;
	jacobian[0][1] = -0.5e0 * t10;
	jacobian[0][2] = -0.5e0 * t18 - 0.5e0 * t20;
	jacobian[0][3] = 0.5e0 * t27;
	jacobian[0][4] = -0.5e0 * t31 * L4;
	jacobian[0][5] = -0.5e0 * t40 + 0.5e0 * t42;
	jacobian[0][6] = 0.0e0;
	jacobian[1][0] = 0.5e0 * t14;
	jacobian[1][1] = 0.5e0 * t16;
	jacobian[1][2] = 0.0e0;
	jacobian[1][3] = 0.5e0 * t36;
	jacobian[1][4] = 0.5e0 * t38;
	jacobian[1][5] = 0.0e0;
	jacobian[1][6] = 0.0e0;
	jacobian[2][0] = -0.5e0 * t50;
	jacobian[2][1] = 0.5e0 * t53;
	jacobian[2][2] = -0.5e0 * t55 + 0.5e0 * t57;
	jacobian[2][3] = -0.5e0 * t61;
	jacobian[2][4] = 0.5e0 * t63 * L4;
	jacobian[2][5] = -0.5e0 * t66 - 0.5e0 * t68;
	jacobian[2][6] = 0.0e0;
	jacobian[3][0] = (t72 * t110 + t112 * t157) * t168 + (-t112 * t110 + t72 * t157) * t175 + (-t132 / 0.2e1 - t178 * t76) * t100 * t80;
	jacobian[3][1] = (t72 * t199 + t112 * t229) * t168 + (-t112 * t199 + t72 * t229) * t175 + (-t210 / 0.2e1 + t178 * t77) * t100 * t80;
	jacobian[3][2] = (t72 * t255 + t112 * t284) * t168 + (-t112 * t255 + t72 * t284) * t175 + (-t266 / 0.2e1 + t269) * t100 * t80;
	jacobian[3][3] = (t72 * t314 + t112 * t341) * t168 + (-t112 * t314 + t72 * t341) * t175 + (-t324 / 0.2e1 + t350 * t78) * t100 * t80;
	jacobian[3][4] = (t72 * t378 + t112 * t412) * t168 + (-t112 * t378 + t72 * t412) * t175 + (-t390 / 0.2e1 - t350 * t79) * t100 * t80;
	jacobian[3][5] = (t72 * t438 + t112 * t469) * t168 + (-t112 * t438 + t72 * t469) * t175 + (-t451 / 0.2e1 + t454) * t100 * t80;
	jacobian[3][6] = t487 * t168 + t491 * t175;
	jacobian[4][0] = -(t72 * t155 + t112 * t505) * t491 + (-t112 * t155 + t72 * t505) * t487 + (-t126 / 0.2e1 + t123 * t76) * t100 * t83;
	jacobian[4][1] = -(t72 * t227 + t112 * t529) * t491 + (-t112 * t227 + t72 * t529) * t487 + (-t206 / 0.2e1 - t123 * t77) * t100 * t83;
	jacobian[4][2] = -(t72 * t282 + t112 * t552) * t491 + (-t112 * t282 + t72 * t552) * t487 + (-t262 / 0.2e1 + t260) * t100 * t83;
	jacobian[4][3] = -(t72 * t339 + t112 * t575) * t491 + (-t112 * t339 + t72 * t575) * t487 + (-t322 / 0.2e1 - t319 * t78) * t100 * t83;
	jacobian[4][4] = -(t72 * t410 + t112 * t599) * t491 + (-t112 * t410 + t72 * t599) * t487 + (-t386 / 0.2e1 + t319 * t79) * t100 * t83;
	jacobian[4][5] = -(t72 * t467 + t112 * t622) * t491 + (-t112 * t467 + t72 * t622) * t487 + (-t446 / 0.2e1 + t443) * t100 * t83;
	jacobian[4][6] = -t640 * t491 + t644 * t487;
	jacobian[5][0] = -(t72 * t137 + t112 * t658) * t644 + (-t112 * t137 + t72 * t658) * t640 + (-t97 / 0.2e1 + t102) * t100 * t74;
	jacobian[5][1] = -(t72 * t214 + t112 * t682) * t644 + (-t112 * t214 + t72 * t682) * t640 + (-t189 / 0.2e1 + t193) * t100 * t74;
	jacobian[5][2] = -(t72 * t271 + t112 * t704) * t644 + (-t112 * t271 + t72 * t704) * t640 - t714 * t251 / 0.2e1;
	jacobian[5][3] = -(t72 * t326 / 0.2e1 + t112 * t729) * t644 + (-t112 * t326 / 0.2e1 + t72 * t729) * t640 + (-t304 / 0.2e1 - t308) * t100 * t74;
	jacobian[5][4] = -(t72 * t393 + t112 * t753) * t644 + (-t112 * t393 + t72 * t753) * t640 + (-t362 / 0.2e1 - t369 * L4) * t100 * t74;
	jacobian[5][5] = -(t72 * t456 + t112 * t776) * t644 + (-t112 * t456 + t72 * t776) * t640 - t714 * t434 / 0.2e1;
	jacobian[5][6] = -t175 * t644 - t168 * t640;

	vel[0] = jacobian[0][0]*qd[0] + jacobian[0][1]*qd[1] + jacobian[0][2]*qd[2] + jacobian[0][3]*qd[3] + jacobian[0][4]*qd[4] + jacobian[0][5]*qd[5] + jacobian[0][6]*qd[6];
	vel[1] = jacobian[1][0]*qd[0] + jacobian[1][1]*qd[1] + jacobian[1][2]*qd[2] + jacobian[1][3]*qd[3] + jacobian[1][4]*qd[4] + jacobian[1][5]*qd[5] + jacobian[1][6]*qd[6];
	vel[2] = jacobian[2][0]*qd[0] + jacobian[2][1]*qd[1] + jacobian[2][2]*qd[2] + jacobian[2][3]*qd[3] + jacobian[2][4]*qd[4] + jacobian[2][5]*qd[5] + jacobian[2][6]*qd[6];
	vel[3] = jacobian[3][0]*qd[0] + jacobian[3][1]*qd[1] + jacobian[3][2]*qd[2] + jacobian[3][3]*qd[3] + jacobian[3][4]*qd[4] + jacobian[3][5]*qd[5] + jacobian[3][6]*qd[6];
	vel[4] = jacobian[4][0]*qd[0] + jacobian[4][1]*qd[1] + jacobian[4][2]*qd[2] + jacobian[4][3]*qd[3] + jacobian[4][4]*qd[4] + jacobian[4][5]*qd[5] + jacobian[4][6]*qd[6];
	vel[5] = jacobian[5][0]*qd[0] + jacobian[5][1]*qd[1] + jacobian[5][2]*qd[2] + jacobian[5][3]*qd[3] + jacobian[5][4]*qd[4] + jacobian[5][5]*qd[5] + jacobian[5][6]*qd[6];

	return 1;
}

/******************************************************************************* 
T3 Kinematics Functions
********************************************************************************/
/*
int forwardKinematics_t3left(double *q, double *task)
{

	double PI = 3.1415926536;
	double phi = PI/4;
	double alpha = 10*PI/180;
	double L1 = 185;
	double L2 = 250;
	double L3 = 280;

	double t1 = cos(alpha);
	double t2 = cos(q[5]);
	double t3 = t1 * t2;
	double t4 = q[3] + phi;
	double t5 = sin(t4);
	double t7 = q[4] + phi;
	double t8 = cos(t7);
	double t10 = t5 * L3 + t8 * L3;
	double t11 = t3 * t10;
	double t13 = sin(alpha);
	double t14 = cos(t4);
	double t16 = sin(t7);
	double t18 = -L2 - t14 * L3 + t16 * L3;
	double t19 = t13 * t18;
	double t21 = cos(q[2]);
	double t23 = q[0] + phi;
	double t24 = sin(t23);
	double t26 = q[1] + phi;
	double t27 = cos(t26);
	double t29 = t24 * L3 + t27 * L3;
	double t30 = t1 * t21 * t29;
	double t32 = cos(t23);
	double t34 = sin(t26);
	double t36 = -L2 - t32 * L3 + t34 * L3;
	double t37 = t13 * t36;
	double t40 = t13 * t2;
	double t41 = t40 * t10;
	double t43 = t1 * t18;
	double t46 = t13 * t21 * t29;
	double t48 = t1 * t36;
	double t51 = sin(q[5]);
	double t52 = t51 * t10;
	double t54 = sin(q[2]);
	double t55 = t54 * t29;
	double t58 = cos(q[6]);
	double t62 = t30 - t37 - t11 + t19;
	double t63 = t62 * t62;
	double t64 = t46 + t48 - t41 - t43;
	double t65 = t64 * t64;
	double t66 = L1 - t55 + t52;
	double t67 = t66 * t66;
	double t69 = sqrt(t63 + t65 + t67);
	double t70 = 0.1e1 / t69;
	double t71 = (t40 * t8 + t1 * t16) * t70;
	double t73 = t51 * t8;
	double t74 = t70 * t64;
	double t76 = t71 * t66 + t73 * t74;
	double t78 = sin(q[6]);
	double t82 = (t3 * t8 - t13 * t16) * t70;
	double t85 = t82 * t64 - t71 * t62;
	double t87 = t70 * t66;
	double t88 = t70 * t62;
	double t91 = -t73 * t88 - t82 * t66;
	double t93 = t74 * t85 - t87 * t91;
	double t102 = t87 * t76 - t88 * t85;
	double t111 = t88 * t91 - t74 * t76;
	task[0] = 0.5e0 * t11 - 0.5e0 * t19 + 0.5e0 * t30 - 0.5e0 * t37;
	task[1] = 0.5e0 * t41 + 0.5e0 * t43 + 0.5e0 * t46 + 0.5e0 * t48;
	task[2] = -0.5e0 * t52 - 0.5e0 * t55;
	task[3] = t58 * t76 + t78 * t93;
	task[4] = -t78 * t76 + t58 * t93;
	task[5] = t88;
	task[6] = t58 * t91 + t78 * t102;
	task[7] = -t78 * t91 + t58 * t102;
	task[8] = t74;
	task[9] = t58 * t85 + t78 * t111;
	task[10] = -t78 * t85 + t58 * t111;
	task[11] = t87;

	return 1;
}

int velocityKinematics_t3left(double *q, double *qd, double *vel)
{
	double jacobian[6][7];
	double PI = 3.1415926536;
	double phi = PI/4;
	double alpha = 10*PI/180;
	double L1 = 185;
	double L2 = 250;
	double L3 = 280;
	
	

	vel[0] = jacobian[0][0]*qd[0] + jacobian[0][1]*qd[1] + jacobian[0][2]*qd[2] + jacobian[0][3]*qd[3] + jacobian[0][4]*qd[4] + jacobian[0][5]*qd[5] + jacobian[0][6]*qd[6];
	vel[1] = jacobian[1][0]*qd[0] + jacobian[1][1]*qd[1] + jacobian[1][2]*qd[2] + jacobian[1][3]*qd[3] + jacobian[1][4]*qd[4] + jacobian[1][5]*qd[5] + jacobian[1][6]*qd[6];
	vel[2] = jacobian[2][0]*qd[0] + jacobian[2][1]*qd[1] + jacobian[2][2]*qd[2] + jacobian[2][3]*qd[3] + jacobian[2][4]*qd[4] + jacobian[2][5]*qd[5] + jacobian[2][6]*qd[6];
	vel[3] = jacobian[3][0]*qd[0] + jacobian[3][1]*qd[1] + jacobian[3][2]*qd[2] + jacobian[3][3]*qd[3] + jacobian[3][4]*qd[4] + jacobian[3][5]*qd[5] + jacobian[3][6]*qd[6];
	vel[4] = jacobian[4][0]*qd[0] + jacobian[4][1]*qd[1] + jacobian[4][2]*qd[2] + jacobian[4][3]*qd[3] + jacobian[4][4]*qd[4] + jacobian[4][5]*qd[5] + jacobian[4][6]*qd[6];
	vel[5] = jacobian[5][0]*qd[0] + jacobian[5][1]*qd[1] + jacobian[5][2]*qd[2] + jacobian[5][3]*qd[3] + jacobian[5][4]*qd[4] + jacobian[5][5]*qd[5] + jacobian[5][6]*qd[6];

	return 1;
}

*/