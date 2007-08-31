#ifndef __WORKER_PROTOCOL_H
#define __WORKER_PROTOCOL_H


namespace nix {


#define WORKER_MAGIC_1 0x6e697864
#define WORKER_MAGIC_2 0x6478696e


typedef enum {
    wopQuit,								//0
    wopIsValidPath,							
    wopIsValidStatePath,
    wopIsValidComponentOrStatePath,
    wopQuerySubstitutes,
    wopHasSubstitutes,
    wopQueryPathHash,
    wopQueryStatePathDrv,
    wopQueryReferences,
    wopQueryStateReferences,
    wopQueryReferrers,						//10
    wopQueryStateReferrers,					
    wopAddToStore,							
    wopAddTextToStore,
    wopBuildDerivations,					//TODO !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! HANGS SOMETIMES !!!!!
    wopEnsurePath,
    wopAddTempRoot,
    wopAddIndirectRoot,
    wopSyncWithGC,
    wopFindRoots,
    wopCollectGarbage,						//20
    wopExportPath,							
    wopImportPath,
    wopQueryDeriver,
    wopQueryDerivers,
    wopSetStatePathsInterval,
	wopGetStatePathsInterval,
	wopIsStateComponent,
	wopStorePathRequisites,
	wopSetStateRevisions,
	wopQueryStateRevisions,					//30
	wopQueryAvailableStateRevisions,		
	wopCommitStatePath,
	wopScanAndUpdateAllReferences,
	wopToNonSharedPathSet,
	wopRevertToRevision,
	wopSetSharedState,
} WorkerOp;


#define STDERR_NEXT  0x6f6c6d67
#define STDERR_READ  0x64617461 // data needed from source
#define STDERR_WRITE 0x64617416 // data for sink
#define STDERR_LAST  0x616c7473
#define STDERR_ERROR 0x63787470


/* The default location of the daemon socket, relative to
   nixStateDir. */
#define DEFAULT_SOCKET_PATH "/daemon.socket"


Path readStorePath(Source & from);
PathSet readStorePaths(Source & from);

    
}


#endif /* !__WORKER_PROTOCOL_H */
