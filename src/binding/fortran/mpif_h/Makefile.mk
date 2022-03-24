## DO NOT EDIT
## This file created by buildiface 
##
## vim: set ft=automake :

# ensure that the buildiface script ends up in the release tarball
EXTRA_DIST += src/binding/fortran/mpif_h/buildiface

# FIXME need to add proper rules to rebuild the fortran sources generated by
# buildiface when buildiface is updated
if MAINTAINER_MODE
$(top_srcdir)/src/binding/fortran/mpif_h/Makefile.mk: src/binding/fortran/mpif_h/buildiface-stamp

src/binding/fortran/mpif_h/buildiface-stamp: $(top_srcdir)/src/binding/fortran/mpif_h/buildiface $(top_srcdir)/src/include/mpi.h.in
	( cd $(top_srcdir)/src/binding/fortran/mpif_h && ./buildiface )
endif MAINTAINER_MODE

if BUILD_F77_BINDING
mpi_f77_sources += src/binding/fortran/mpif_h/sendf.c \
	src/binding/fortran/mpif_h/recvf.c \
	src/binding/fortran/mpif_h/get_countf.c \
	src/binding/fortran/mpif_h/bsendf.c src/binding/fortran/mpif_h/ssendf.c \
	src/binding/fortran/mpif_h/rsendf.c \
	src/binding/fortran/mpif_h/bufattachf.c \
	src/binding/fortran/mpif_h/bufdetachf.c \
	src/binding/fortran/mpif_h/isendf.c \
	src/binding/fortran/mpif_h/ibsendf.c \
	src/binding/fortran/mpif_h/issendf.c \
	src/binding/fortran/mpif_h/irsendf.c \
	src/binding/fortran/mpif_h/irecvf.c src/binding/fortran/mpif_h/waitf.c \
	src/binding/fortran/mpif_h/testf.c \
	src/binding/fortran/mpif_h/request_freef.c \
	src/binding/fortran/mpif_h/waitanyf.c \
	src/binding/fortran/mpif_h/testanyf.c \
	src/binding/fortran/mpif_h/waitallf.c \
	src/binding/fortran/mpif_h/testallf.c \
	src/binding/fortran/mpif_h/waitsomef.c \
	src/binding/fortran/mpif_h/testsomef.c \
	src/binding/fortran/mpif_h/iprobef.c \
	src/binding/fortran/mpif_h/probef.c \
	src/binding/fortran/mpif_h/cancelf.c \
	src/binding/fortran/mpif_h/testcancelf.c \
	src/binding/fortran/mpif_h/send_initf.c \
	src/binding/fortran/mpif_h/bsend_initf.c \
	src/binding/fortran/mpif_h/ssend_initf.c \
	src/binding/fortran/mpif_h/rsend_initf.c \
	src/binding/fortran/mpif_h/recv_initf.c \
	src/binding/fortran/mpif_h/startf.c \
	src/binding/fortran/mpif_h/startallf.c \
	src/binding/fortran/mpif_h/sendrecvf.c \
	src/binding/fortran/mpif_h/sndrcvrplf.c \
	src/binding/fortran/mpif_h/typecontigf.c \
	src/binding/fortran/mpif_h/type_vectorf.c \
	src/binding/fortran/mpif_h/type_hvectorf.c \
	src/binding/fortran/mpif_h/type_indexedf.c \
	src/binding/fortran/mpif_h/type_hindexedf.c \
	src/binding/fortran/mpif_h/type_structf.c \
	src/binding/fortran/mpif_h/type_extentf.c \
	src/binding/fortran/mpif_h/type_sizef.c \
	src/binding/fortran/mpif_h/type_lbf.c \
	src/binding/fortran/mpif_h/type_ubf.c \
	src/binding/fortran/mpif_h/type_commitf.c \
	src/binding/fortran/mpif_h/type_freef.c \
	src/binding/fortran/mpif_h/get_elementsf.c \
	src/binding/fortran/mpif_h/packf.c src/binding/fortran/mpif_h/unpackf.c \
	src/binding/fortran/mpif_h/pack_sizef.c \
	src/binding/fortran/mpif_h/barrierf.c \
	src/binding/fortran/mpif_h/bcastf.c \
	src/binding/fortran/mpif_h/gatherf.c \
	src/binding/fortran/mpif_h/gathervf.c \
	src/binding/fortran/mpif_h/scatterf.c \
	src/binding/fortran/mpif_h/scattervf.c \
	src/binding/fortran/mpif_h/allgatherf.c \
	src/binding/fortran/mpif_h/allgathervf.c \
	src/binding/fortran/mpif_h/alltoallf.c \
	src/binding/fortran/mpif_h/alltoallvf.c \
	src/binding/fortran/mpif_h/alltoallwf.c \
	src/binding/fortran/mpif_h/exscanf.c \
	src/binding/fortran/mpif_h/reducef.c \
	src/binding/fortran/mpif_h/op_createf.c \
	src/binding/fortran/mpif_h/op_freef.c \
	src/binding/fortran/mpif_h/allreducef.c \
	src/binding/fortran/mpif_h/redscatf.c \
	src/binding/fortran/mpif_h/scanf.c \
	src/binding/fortran/mpif_h/group_sizef.c \
	src/binding/fortran/mpif_h/group_rankf.c \
	src/binding/fortran/mpif_h/grouptranksf.c \
	src/binding/fortran/mpif_h/group_comparef.c \
	src/binding/fortran/mpif_h/comm_groupf.c \
	src/binding/fortran/mpif_h/group_unionf.c \
	src/binding/fortran/mpif_h/groupinterf.c \
	src/binding/fortran/mpif_h/groupdifff.c \
	src/binding/fortran/mpif_h/group_inclf.c \
	src/binding/fortran/mpif_h/group_exclf.c \
	src/binding/fortran/mpif_h/grouprinclf.c \
	src/binding/fortran/mpif_h/grouprexclf.c \
	src/binding/fortran/mpif_h/group_freef.c \
	src/binding/fortran/mpif_h/comm_sizef.c \
	src/binding/fortran/mpif_h/comm_rankf.c \
	src/binding/fortran/mpif_h/comm_comparef.c \
	src/binding/fortran/mpif_h/comm_dupf.c \
	src/binding/fortran/mpif_h/comm_dup_with_infof.c \
	src/binding/fortran/mpif_h/comm_createf.c \
	src/binding/fortran/mpif_h/comm_splitf.c \
	src/binding/fortran/mpif_h/comm_freef.c \
	src/binding/fortran/mpif_h/commtesticf.c \
	src/binding/fortran/mpif_h/commrsizef.c \
	src/binding/fortran/mpif_h/commrgroupf.c \
	src/binding/fortran/mpif_h/iccreatef.c \
	src/binding/fortran/mpif_h/icmergef.c \
	src/binding/fortran/mpif_h/keyval_freef.c \
	src/binding/fortran/mpif_h/attr_putf.c \
	src/binding/fortran/mpif_h/attr_getf.c \
	src/binding/fortran/mpif_h/attr_deletef.c \
	src/binding/fortran/mpif_h/topo_testf.c \
	src/binding/fortran/mpif_h/cart_createf.c \
	src/binding/fortran/mpif_h/dims_createf.c \
	src/binding/fortran/mpif_h/graph_createf.c \
	src/binding/fortran/mpif_h/graphdims_getf.c \
	src/binding/fortran/mpif_h/graph_getf.c \
	src/binding/fortran/mpif_h/cartdim_getf.c \
	src/binding/fortran/mpif_h/cart_getf.c \
	src/binding/fortran/mpif_h/cart_rankf.c \
	src/binding/fortran/mpif_h/cart_coordsf.c \
	src/binding/fortran/mpif_h/grfnbcountf.c \
	src/binding/fortran/mpif_h/grfnbrsf.c \
	src/binding/fortran/mpif_h/cart_shiftf.c \
	src/binding/fortran/mpif_h/cart_subf.c \
	src/binding/fortran/mpif_h/cart_mapf.c \
	src/binding/fortran/mpif_h/graph_mapf.c \
	src/binding/fortran/mpif_h/getpnamef.c \
	src/binding/fortran/mpif_h/get_versionf.c \
	src/binding/fortran/mpif_h/get_library_versionf.c \
	src/binding/fortran/mpif_h/errhcreatef.c \
	src/binding/fortran/mpif_h/errhsetf.c \
	src/binding/fortran/mpif_h/errhgetf.c \
	src/binding/fortran/mpif_h/errhfreef.c \
	src/binding/fortran/mpif_h/error_stringf.c \
	src/binding/fortran/mpif_h/error_classf.c \
	src/binding/fortran/mpif_h/finalizef.c \
	src/binding/fortran/mpif_h/initializedf.c \
	src/binding/fortran/mpif_h/abortf.c \
	src/binding/fortran/mpif_h/close_portf.c \
	src/binding/fortran/mpif_h/comm_acceptf.c \
	src/binding/fortran/mpif_h/comm_connectf.c \
	src/binding/fortran/mpif_h/commdiscf.c \
	src/binding/fortran/mpif_h/commparentf.c \
	src/binding/fortran/mpif_h/comm_joinf.c \
	src/binding/fortran/mpif_h/comm_spawnf.c \
	src/binding/fortran/mpif_h/spawnmultf.c \
	src/binding/fortran/mpif_h/lookup_namef.c \
	src/binding/fortran/mpif_h/open_portf.c \
	src/binding/fortran/mpif_h/publish_namef.c \
	src/binding/fortran/mpif_h/unpubnamef.c \
	src/binding/fortran/mpif_h/comm_set_infof.c \
	src/binding/fortran/mpif_h/comm_get_infof.c \
	src/binding/fortran/mpif_h/accumulatef.c \
	src/binding/fortran/mpif_h/getf.c src/binding/fortran/mpif_h/putf.c \
	src/binding/fortran/mpif_h/win_completef.c \
	src/binding/fortran/mpif_h/win_createf.c \
	src/binding/fortran/mpif_h/win_fencef.c \
	src/binding/fortran/mpif_h/win_freef.c \
	src/binding/fortran/mpif_h/win_get_groupf.c \
	src/binding/fortran/mpif_h/win_lockf.c \
	src/binding/fortran/mpif_h/win_postf.c \
	src/binding/fortran/mpif_h/win_startf.c \
	src/binding/fortran/mpif_h/win_testf.c \
	src/binding/fortran/mpif_h/win_unlockf.c \
	src/binding/fortran/mpif_h/win_waitf.c \
	src/binding/fortran/mpif_h/win_allocatef.c \
	src/binding/fortran/mpif_h/win_allocate_sharedf.c \
	src/binding/fortran/mpif_h/win_shared_queryf.c \
	src/binding/fortran/mpif_h/win_create_dynamicf.c \
	src/binding/fortran/mpif_h/win_attachf.c \
	src/binding/fortran/mpif_h/win_detachf.c \
	src/binding/fortran/mpif_h/win_get_infof.c \
	src/binding/fortran/mpif_h/win_set_infof.c \
	src/binding/fortran/mpif_h/get_accumulatef.c \
	src/binding/fortran/mpif_h/fetch_and_opf.c \
	src/binding/fortran/mpif_h/compare_and_swapf.c \
	src/binding/fortran/mpif_h/rputf.c src/binding/fortran/mpif_h/rgetf.c \
	src/binding/fortran/mpif_h/raccumulatef.c \
	src/binding/fortran/mpif_h/rget_accumulatef.c \
	src/binding/fortran/mpif_h/win_lock_allf.c \
	src/binding/fortran/mpif_h/win_unlock_allf.c \
	src/binding/fortran/mpif_h/win_flushf.c \
	src/binding/fortran/mpif_h/win_flush_allf.c \
	src/binding/fortran/mpif_h/win_flush_localf.c \
	src/binding/fortran/mpif_h/win_flush_local_allf.c \
	src/binding/fortran/mpif_h/win_syncf.c \
	src/binding/fortran/mpif_h/adderrclassf.c \
	src/binding/fortran/mpif_h/adderrcodef.c \
	src/binding/fortran/mpif_h/adderrstringf.c \
	src/binding/fortran/mpif_h/commcallerrf.c \
	src/binding/fortran/mpif_h/commnewkeyf.c \
	src/binding/fortran/mpif_h/commdelattrf.c \
	src/binding/fortran/mpif_h/commfreekeyf.c \
	src/binding/fortran/mpif_h/comm_get_attrf.c \
	src/binding/fortran/mpif_h/commgetnamf.c \
	src/binding/fortran/mpif_h/comm_set_attrf.c \
	src/binding/fortran/mpif_h/comm_set_namef.c \
	src/binding/fortran/mpif_h/filecallerrf.c \
	src/binding/fortran/mpif_h/greqcompletef.c \
	src/binding/fortran/mpif_h/greqstartf.c \
	src/binding/fortran/mpif_h/isthrmainf.c \
	src/binding/fortran/mpif_h/query_threadf.c \
	src/binding/fortran/mpif_h/statgetclf.c \
	src/binding/fortran/mpif_h/statsetelf.c \
	src/binding/fortran/mpif_h/typenewkeyf.c \
	src/binding/fortran/mpif_h/typedelattrf.c \
	src/binding/fortran/mpif_h/type_dupf.c \
	src/binding/fortran/mpif_h/typefreekeyf.c \
	src/binding/fortran/mpif_h/type_get_attrf.c \
	src/binding/fortran/mpif_h/typegetcntsf.c \
	src/binding/fortran/mpif_h/typegetenvf.c \
	src/binding/fortran/mpif_h/typegnamef.c \
	src/binding/fortran/mpif_h/typesetattrf.c \
	src/binding/fortran/mpif_h/typesetnamef.c \
	src/binding/fortran/mpif_h/type_match_sizef.c \
	src/binding/fortran/mpif_h/wincallerrf.c \
	src/binding/fortran/mpif_h/winnewkeyf.c \
	src/binding/fortran/mpif_h/windelattrf.c \
	src/binding/fortran/mpif_h/winfreekeyf.c \
	src/binding/fortran/mpif_h/win_get_attrf.c \
	src/binding/fortran/mpif_h/win_get_namef.c \
	src/binding/fortran/mpif_h/win_set_attrf.c \
	src/binding/fortran/mpif_h/win_set_namef.c \
	src/binding/fortran/mpif_h/alloc_memf.c \
	src/binding/fortran/mpif_h/commcreerrf.c \
	src/binding/fortran/mpif_h/commgeterrf.c \
	src/binding/fortran/mpif_h/commseterrf.c \
	src/binding/fortran/mpif_h/filecreerrf.c \
	src/binding/fortran/mpif_h/filegeterrf.c \
	src/binding/fortran/mpif_h/fileseterrf.c \
	src/binding/fortran/mpif_h/finalizedf.c \
	src/binding/fortran/mpif_h/free_memf.c \
	src/binding/fortran/mpif_h/info_createf.c \
	src/binding/fortran/mpif_h/info_deletef.c \
	src/binding/fortran/mpif_h/info_dupf.c \
	src/binding/fortran/mpif_h/info_freef.c \
	src/binding/fortran/mpif_h/info_getf.c \
	src/binding/fortran/mpif_h/infognkf.c \
	src/binding/fortran/mpif_h/infognthkf.c \
	src/binding/fortran/mpif_h/infovallenf.c \
	src/binding/fortran/mpif_h/info_setf.c \
	src/binding/fortran/mpif_h/pack_externalf.c \
	src/binding/fortran/mpif_h/packesizef.c \
	src/binding/fortran/mpif_h/reqgetstatf.c \
	src/binding/fortran/mpif_h/typedarrayf.c \
	src/binding/fortran/mpif_h/typechindf.c \
	src/binding/fortran/mpif_h/typechvecf.c \
	src/binding/fortran/mpif_h/typecindbf.c \
	src/binding/fortran/mpif_h/type_create_hindexed_blockf.c \
	src/binding/fortran/mpif_h/typecresizef.c \
	src/binding/fortran/mpif_h/typecstructf.c \
	src/binding/fortran/mpif_h/typecsubarrf.c \
	src/binding/fortran/mpif_h/typegetextentf.c \
	src/binding/fortran/mpif_h/typegtextf.c \
	src/binding/fortran/mpif_h/unpackextf.c \
	src/binding/fortran/mpif_h/wincreerrf.c \
	src/binding/fortran/mpif_h/wingeterrf.c \
	src/binding/fortran/mpif_h/winseterrf.c \
	src/binding/fortran/mpif_h/reduce_localf.c \
	src/binding/fortran/mpif_h/op_commutativef.c \
	src/binding/fortran/mpif_h/reduce_scatter_blockf.c \
	src/binding/fortran/mpif_h/dist_graph_create_adjacentf.c \
	src/binding/fortran/mpif_h/dist_graph_createf.c \
	src/binding/fortran/mpif_h/dist_graph_neighbors_countf.c \
	src/binding/fortran/mpif_h/dist_graph_neighborsf.c \
	src/binding/fortran/mpif_h/improbef.c \
	src/binding/fortran/mpif_h/imrecvf.c \
	src/binding/fortran/mpif_h/mprobef.c \
	src/binding/fortran/mpif_h/mrecvf.c \
	src/binding/fortran/mpif_h/comm_idupf.c \
	src/binding/fortran/mpif_h/ibarrierf.c \
	src/binding/fortran/mpif_h/ibcastf.c \
	src/binding/fortran/mpif_h/igatherf.c \
	src/binding/fortran/mpif_h/igathervf.c \
	src/binding/fortran/mpif_h/iscatterf.c \
	src/binding/fortran/mpif_h/iscattervf.c \
	src/binding/fortran/mpif_h/iallgatherf.c \
	src/binding/fortran/mpif_h/iallgathervf.c \
	src/binding/fortran/mpif_h/ialltoallf.c \
	src/binding/fortran/mpif_h/ialltoallvf.c \
	src/binding/fortran/mpif_h/ialltoallwf.c \
	src/binding/fortran/mpif_h/ireducef.c \
	src/binding/fortran/mpif_h/iallreducef.c \
	src/binding/fortran/mpif_h/ireduce_scatterf.c \
	src/binding/fortran/mpif_h/ireduce_scatter_blockf.c \
	src/binding/fortran/mpif_h/iscanf.c \
	src/binding/fortran/mpif_h/iexscanf.c \
	src/binding/fortran/mpif_h/ineighbor_allgatherf.c \
	src/binding/fortran/mpif_h/ineighbor_allgathervf.c \
	src/binding/fortran/mpif_h/ineighbor_alltoallf.c \
	src/binding/fortran/mpif_h/ineighbor_alltoallvf.c \
	src/binding/fortran/mpif_h/ineighbor_alltoallwf.c \
	src/binding/fortran/mpif_h/neighbor_allgatherf.c \
	src/binding/fortran/mpif_h/neighbor_allgathervf.c \
	src/binding/fortran/mpif_h/neighbor_alltoallf.c \
	src/binding/fortran/mpif_h/neighbor_alltoallvf.c \
	src/binding/fortran/mpif_h/neighbor_alltoallwf.c \
	src/binding/fortran/mpif_h/comm_split_typef.c \
	src/binding/fortran/mpif_h/get_elements_xf.c \
	src/binding/fortran/mpif_h/status_set_elements_xf.c \
	src/binding/fortran/mpif_h/type_get_extent_xf.c \
	src/binding/fortran/mpif_h/type_get_true_extent_xf.c \
	src/binding/fortran/mpif_h/type_size_xf.c \
	src/binding/fortran/mpif_h/comm_create_groupf.c \
	src/binding/fortran/mpif_h/comm_failure_ackf.c \
	src/binding/fortran/mpif_h/comm_failure_get_ackedf.c \
	src/binding/fortran/mpif_h/comm_revokef.c \
	src/binding/fortran/mpif_h/comm_shrinkf.c \
	src/binding/fortran/mpif_h/comm_agreef.c \
	src/binding/fortran/mpif_h/file_openf.c \
	src/binding/fortran/mpif_h/file_closef.c \
	src/binding/fortran/mpif_h/file_deletef.c \
	src/binding/fortran/mpif_h/file_set_sizef.c \
	src/binding/fortran/mpif_h/file_preallocatef.c \
	src/binding/fortran/mpif_h/file_get_sizef.c \
	src/binding/fortran/mpif_h/file_get_groupf.c \
	src/binding/fortran/mpif_h/file_get_amodef.c \
	src/binding/fortran/mpif_h/file_set_infof.c \
	src/binding/fortran/mpif_h/file_get_infof.c \
	src/binding/fortran/mpif_h/file_set_viewf.c \
	src/binding/fortran/mpif_h/file_get_viewf.c \
	src/binding/fortran/mpif_h/file_read_atf.c \
	src/binding/fortran/mpif_h/file_read_at_allf.c \
	src/binding/fortran/mpif_h/file_write_atf.c \
	src/binding/fortran/mpif_h/file_write_at_allf.c \
	src/binding/fortran/mpif_h/file_iread_atf.c \
	src/binding/fortran/mpif_h/file_iwrite_atf.c \
	src/binding/fortran/mpif_h/file_readf.c \
	src/binding/fortran/mpif_h/file_read_allf.c \
	src/binding/fortran/mpif_h/file_writef.c \
	src/binding/fortran/mpif_h/file_write_allf.c \
	src/binding/fortran/mpif_h/file_ireadf.c \
	src/binding/fortran/mpif_h/file_iwritef.c \
	src/binding/fortran/mpif_h/file_seekf.c \
	src/binding/fortran/mpif_h/file_get_positionf.c \
	src/binding/fortran/mpif_h/file_get_byte_offsetf.c \
	src/binding/fortran/mpif_h/file_read_sharedf.c \
	src/binding/fortran/mpif_h/file_write_sharedf.c \
	src/binding/fortran/mpif_h/file_iread_sharedf.c \
	src/binding/fortran/mpif_h/file_iwrite_sharedf.c \
	src/binding/fortran/mpif_h/file_read_orderedf.c \
	src/binding/fortran/mpif_h/file_write_orderedf.c \
	src/binding/fortran/mpif_h/file_seek_sharedf.c \
	src/binding/fortran/mpif_h/file_get_position_sharedf.c \
	src/binding/fortran/mpif_h/file_read_at_all_beginf.c \
	src/binding/fortran/mpif_h/file_read_at_all_endf.c \
	src/binding/fortran/mpif_h/file_write_at_all_beginf.c \
	src/binding/fortran/mpif_h/file_write_at_all_endf.c \
	src/binding/fortran/mpif_h/file_read_all_beginf.c \
	src/binding/fortran/mpif_h/file_read_all_endf.c \
	src/binding/fortran/mpif_h/file_write_all_beginf.c \
	src/binding/fortran/mpif_h/file_write_all_endf.c \
	src/binding/fortran/mpif_h/file_read_ordered_beginf.c \
	src/binding/fortran/mpif_h/file_read_ordered_endf.c \
	src/binding/fortran/mpif_h/file_write_ordered_beginf.c \
	src/binding/fortran/mpif_h/file_write_ordered_endf.c \
	src/binding/fortran/mpif_h/file_get_type_extentf.c \
	src/binding/fortran/mpif_h/register_datarepf.c \
	src/binding/fortran/mpif_h/file_set_atomicityf.c \
	src/binding/fortran/mpif_h/file_get_atomicityf.c \
	src/binding/fortran/mpif_h/file_syncf.c \
	src/binding/fortran/mpif_h/file_iread_at_allf.c \
	src/binding/fortran/mpif_h/file_iwrite_at_allf.c \
	src/binding/fortran/mpif_h/file_iread_allf.c \
	src/binding/fortran/mpif_h/file_iwrite_allf.c \
	src/binding/fortran/mpif_h/initf.c \
	src/binding/fortran/mpif_h/initthreadf.c \
	src/binding/fortran/mpif_h/pcontrolf.c \
	src/binding/fortran/mpif_h/addressf.c \
	src/binding/fortran/mpif_h/getaddressf.c \
	src/binding/fortran/mpif_h/wtimef.c src/binding/fortran/mpif_h/wtickf.c \
	src/binding/fortran/mpif_h/aint_addf.c \
	src/binding/fortran/mpif_h/aint_difff.c \
	src/binding/fortran/mpif_h/keyval_createf.c \
	src/binding/fortran/mpif_h/dup_fnf.c \
	src/binding/fortran/mpif_h/null_del_fnf.c \
	src/binding/fortran/mpif_h/null_copy_fnf.c \
	src/binding/fortran/mpif_h/dup_comm_fnf.c \
	src/binding/fortran/mpif_h/null_comm_del_fnf.c \
	src/binding/fortran/mpif_h/null_comm_copy_fnf.c \
	src/binding/fortran/mpif_h/dup_win_fnf.c \
	src/binding/fortran/mpif_h/null_win_del_fnf.c \
	src/binding/fortran/mpif_h/null_win_copy_fnf.c \
	src/binding/fortran/mpif_h/dup_type_fnf.c \
	src/binding/fortran/mpif_h/null_type_del_fnf.c \
	src/binding/fortran/mpif_h/null_type_copy_fnf.c 
mpi_core_sources += src/binding/fortran/mpif_h/fdebug.c \
		src/binding/fortran/mpif_h/setbot.c \
        src/binding/fortran/mpif_h/fortran_ops.F \
		src/binding/fortran/mpif_h/setbotf.f
mpi_sources += src/binding/fortran/mpif_h/statusf2c.c src/binding/fortran/mpif_h/statusc2f.c

# FIXME does AM_CPPFLAGS need to be included elsewhere somehow in the
# target-specific variable?
AM_CPPFLAGS += -I${master_top_srcdir}/src/binding/fortran/mpif_h


noinst_HEADERS += src/binding/fortran/mpif_h/fproto.h src/binding/fortran/mpif_h/mpi_fortimpl.h

# config.status copies src/binding/fortran/mpif_h/mpif.h to src/include (see the relevant
# AC_OUTPUT_COMMANDS in configure.ac), so we need to delete it at distclean time
# too.  More work is needed in this Makefile.mk to keep src/include/mpif.h up to
# date w.r.t. the src/binding/fortran/mpif_h version.
DISTCLEANFILES += src/binding/fortran/mpif_h/mpif.h src/include/mpif.h
nodist_include_HEADERS += src/binding/fortran/mpif_h/mpif.h


endif BUILD_F77_BINDING

