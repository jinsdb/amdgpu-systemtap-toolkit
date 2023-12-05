#stap kfdioctl_params.stp -g -F -o `pwd`/kfdioctl -S 3,3
#stap verify_pts.stp -g -DMAXMAPENTRIES=10000 -DMAXACTION=102400 -F -S 1,3 -o `pwd`/pg_tb
cat kfdioctl_params.stp verify_pts.stp \
|stap -g -DSTP_NO_OVERLOAD -DMAXMAPENTRIES=10000 -DMAXACTION=102400 -F -o `pwd`/kfdump -S 3,3 -