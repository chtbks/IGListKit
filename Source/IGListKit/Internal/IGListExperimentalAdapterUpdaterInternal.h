/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <Foundation/Foundation.h>
#import <QuartzCore/QuartzCore.h>

#import <IGListDiffKit/IGListMoveIndexPath.h>
#import <IGListKit/IGListUpdatingDelegateExperimental.h>

#import "IGListExperimentalAdapterUpdater.h"
#import "IGListBatchUpdateState.h"
#import "IGListItemUpdatesCollector.h"
#import "IGListUpdateTransactionBuilder.h"

NS_ASSUME_NONNULL_BEGIN

@interface IGListExperimentalAdapterUpdater ()

@property (nonatomic, strong, readonly) IGListUpdateTransactionBuilder *transactionBuilder;

@property (nonatomic, strong) NSMutableArray<IGListUpdatingCompletion> *inUpdateCompletionBlocks;
@property (nonatomic, strong) IGListItemUpdatesCollector *inUpdateItemCollector;

@property (nonatomic, assign) IGListBatchUpdateState state;
@property (nonatomic, strong, nullable) IGListBatchUpdateData *applyingUpdateData;

- (void)performReloadDataWithCollectionViewBlock:(IGListCollectionViewBlock)collectionViewBlock;
- (void)performBatchUpdatesWithCollectionViewBlock:(IGListCollectionViewBlock)collectionViewBlock;
- (void)cleanStateBeforeUpdates;
- (BOOL)hasChanges;

@end

NS_ASSUME_NONNULL_END