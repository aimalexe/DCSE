
# PlanAhead Launch Script for Post-Synthesis pin planning, created by Project Navigator

create_project -name bcd_counter -dir "D:/eductaion/DCSE/6th Semester/DSD Lab/lab8/task1/bcd_counter/planAhead_run_2" -part xc6slx9csg324-2
set_property design_mode GateLvl [get_property srcset [current_run -impl]]
set_property edif_top_file "D:/eductaion/DCSE/6th Semester/DSD Lab/lab8/task1/bcd_counter/TopMultiplex.ngc" [ get_property srcset [ current_run ] ]
add_files -norecurse { {D:/eductaion/DCSE/6th Semester/DSD Lab/lab8/task1/bcd_counter} }
set_param project.pinAheadLayout  yes
set_property target_constrs_file "TopMultiplex.ucf" [current_fileset -constrset]
add_files [list {TopMultiplex.ucf}] -fileset [get_property constrset [current_run]]
link_design
