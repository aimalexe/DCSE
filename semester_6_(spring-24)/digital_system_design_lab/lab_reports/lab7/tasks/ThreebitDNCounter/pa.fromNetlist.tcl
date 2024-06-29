
# PlanAhead Launch Script for Post-Synthesis pin planning, created by Project Navigator

create_project -name ThreebitDNCounter -dir "H:/6th semester Data/By Hammad/DSD-Lab/Lab 07/Three bit DN Counter/ThreebitDNCounter/planAhead_run_1" -part xc6slx9csg324-2
set_property design_mode GateLvl [get_property srcset [current_run -impl]]
set_property edif_top_file "H:/6th semester Data/By Hammad/DSD-Lab/Lab 07/Three bit DN Counter/ThreebitDNCounter/Top_Module.ngc" [ get_property srcset [ current_run ] ]
add_files -norecurse { {H:/6th semester Data/By Hammad/DSD-Lab/Lab 07/Three bit DN Counter/ThreebitDNCounter} }
set_param project.pinAheadLayout  yes
set_property target_constrs_file "Top_Module.ucf" [current_fileset -constrset]
add_files [list {Top_Module.ucf}] -fileset [get_property constrset [current_run]]
link_design
